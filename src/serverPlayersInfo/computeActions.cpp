// EFRITS
// project:     rts
// created on:  2024-02-21 - 11:00 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: computeActions implementation

#include "serverPlayersInfo.hh"

void ef::ServerPlayersInfo::computeActions(double timePassed)
{
    Packet pack;

    if (serverTcp->loop() && !gameStarted)
    {
        clientConnected.push_back(serverTcp->getLastConnected());
        clientReady.push_back(false);
    }
    if (gameStarted)
        for (int i = 0; i < (int)playersInfo.size(); i += 1)
        {
            updateOther();
            broadcastTarget(playersInfo[i]->computeActions(timePassed, res.getWeaponConf(), false, serverUdp, clientConnected[i]));
        }
    // udp read
    serverUdp->loop();
    while (serverUdp->getData((char *)&pack, sizeof(pack)) != -1)
    {
        int playerId = -1;
        for (int i = 0; i < (int)clientConnected.size(); i += 1)
        {
            struct sockaddr_in tempAddr = serverTcp->getLastConnected();
            if (memcmp((char *)&clientConnected[i], (char *)&tempAddr, sizeof(struct sockaddr_in)) == 0)
                playerId = i;
        }
        if (playerId != -1)
        {
            if (!gameStarted)
            {
                if (pack.type == ISREADY)
                    clientReady[playerId] = pack.ready.isReady;
                int compt = 0;
                for (int i = 0; i < (int)clientReady.size(); i += 1)
                    if (clientReady[i])
                        compt += 1;
                if (compt == (int)clientReady.size())
                {
                    gameStarted = true;
                    Packet pack;
                    pack.type = GAMESTART;
                    pack.gameStart.isStart = true;
                    for (int i = 0; i < (int)clientConnected.size(); i += 1)
                        serverUdp->sendData((char *)&pack, sizeof(Packet), clientConnected[i]);
                }
            }
            else
            {
                if (pack.type == MOVEUNIT)
                    makePath(pack.moveUnit.unitId, pack.moveUnit.dest.get(), pack.moveUnit.moveType, playerId);
                else if (pack.type == SETTARGET)
                    setTarget(pack.setTarget.unitId, pack.setTarget.otherId, playerId, pack.setTarget.isBuilding);
                else if (pack.type == PLACEBUILD)
                    placeBuilding(pack.placeBuild.pos.get(), playerId);
                else if (pack.type == PRODUCE)
                {
                    std::string str(pack.produce.conf, pack.produce.len);
                    produce(pack.produce.producerId, str, playerId, pack.produce.buildType);
                }
            }
        }
        serverUdp->loop();
    }
    if (gameStarted)
    {
        for (int i = 0; i < (int)playersInfo.size(); i += 1)
        {
            playersInfo[i]->finishAction(timePassed, false);
            Packet tempPack;
            std::vector<std::shared_ptr<ef::Object>> & kill = playersInfo[i]->getKillList();
            for (int j = 0; j < (int)kill.size(); j += 1)
            {
                tempPack.type = DESTROY;
                tempPack.destroy.unitId = kill[j]->getId();
                tempPack.destroy.isOther = false;
                std::shared_ptr<ef::Unit> tempUnit = static_pointer_cast<ef::Unit>(kill[j]);
                if (tempUnit.get() == nullptr)
                    tempPack.destroy.isBuilding = true;
                else
                    tempPack.destroy.isBuilding = false;
                serverUdp->loop();
                if (!serverUdp->sendData((char *)&tempPack, sizeof(Packet), clientConnected[i]))
                    i -= 1;
                tempPack.destroy.isOther = true;
                for (int k = i + 1; k < i + (int)clientConnected.size(); k += 1)
                    if (playersInfo[k % playersInfo.size()]->isInVision(kill[j]))
                    {
                        serverUdp->sendData((char *)&tempPack, sizeof(Packet), clientConnected[k % clientConnected.size()]);
                        if (tempPack.destroy.isBuilding)
                            playersInfo[i]->destroyBuilding(static_pointer_cast<Building>(kill[j]), true);
                        else
                            playersInfo[i]->destroyUnit(static_pointer_cast<Unit>(kill[j]), true);
                    }
            }
            kill.clear();
        }
    }
}

