// EFRITS
// project:     rts
// created on:  2024-02-26 - 10:53 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: broadcastTarget implementation

#include "serverPlayersInfo.hh"

void ef::ServerPlayersInfo::broadcastTarget(std::vector<TargetReturn> target)
{
    for (int i = 0; i < (int)target.size(); i += 1)
    {
        PacketUpdateTarget pack;
        pack.type = UPDATETARGET;
	pack.datalen = sizeof(PacketUpdateTarget);
        pack.unitId = target[i].unit->getId();
        pack.isBuilding = target[i].isBuilding;
        pack.isEnemy = true;
        pack.otherLen = target.size();
        for (int j = 0; j < (int)target[i].target.size(); j += 1)
        {
            pack.otherId[j] = target[i].target[j]->getId();
            pack.isEnemyBuilding[j] = target[i].isTargetBuilding[j];
        }
        int playerId = target[i].unit->getAlegence();
        for (int j = playerId + 1; j < (int)clientConnected.size() + playerId; j += 1)
        {
            serverUdp->loop();
            serverUdp->sendData((char *)&pack, pack.datalen, clientConnected[j % clientConnected.size()]);
        }
    }
}

