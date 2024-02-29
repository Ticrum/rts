// EFRITS
// project:     rts
// created on:  2024-02-26 - 16:43 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: computeActions implementation

#include "clientPlayerInfo.hh"

void ef::ClientPlayerInfo::computeActions(double timePassed)
{
    Packet pack;

    if (isConnected)
    {
        if (gameStarted)
            playerInfo.updateOther();
        playerInfo.computeActions(timePassed, res.getWeaponConf(), true, clientUdp, serverConnected);
        clientUdp->loop();
        while (clientUdp->getData((char *)&pack, sizeof(pack)) != -1)
        {
            if (pack.type == GAMESTART && pack.gameStart.isStart)
                gameStarted = true;
            if (gameStarted)
            {
                if (pack.type == DESTROY)
                {
                    if (pack.destroy.isBuilding)
                    {
                        std::shared_ptr<Building> tempBuild = playerInfo.getBuild(pack.destroy.unitId);
                        if (tempBuild.get() != nullptr)
                            playerInfo.destroyBuilding(tempBuild, pack.destroy.isOther);
                    }
                    else
                    {
                        std::shared_ptr<Unit> tempUnit = playerInfo.getUnit(pack.destroy.unitId);
                        if (tempUnit.get() != nullptr)
                            playerInfo.destroyUnit(tempUnit, pack.destroy.isOther);
                    }
                }
                else if (pack.type == ADDOTHERUNIT)
                {
                    std::shared_ptr<Unit> tempUnit;
                    std::string confName(pack.addOtherUnit.conf, pack.addOtherUnit.len);
                    ConfUnit conf = res.getUnit(confName);
                    std::vector<Pos> path;
                    for (int i = 0; i < pack.addOtherUnit.nbrPos; i += 1)
                        path.push_back(pack.addOtherUnit.pos[i].get());
                    std::vector<double> cdr;
                    for (int i = 0; i < pack.addOtherUnit.nbrCdr; i += 1)
                        cdr.push_back(pack.addOtherUnit.cdr[i]);
                    tempUnit.reset(new Unit(conf, pack.addOtherUnit.posi.get(), pack.addOtherUnit.unitId, pack.addOtherUnit.alegence, res.getWeaponConf(), pack.addOtherUnit.actualHp, pack.addOtherUnit.progress, pack.addOtherUnit.moveType, path, cdr));
                    playerInfo.addOther(tempUnit, pack.addOtherUnit.isOther);
                }
                else if (pack.type == ADDOTHERBUILDING)
                {
                    std::shared_ptr<Building> tempBuilding;
                    std::string confName(pack.addOtherBuilding.conf, pack.addOtherBuilding.len);
                    ConfBuilding conf = res.getBuild(confName);
                    std::vector<double> cdr;
                    for (int i = 0; i < pack.addOtherBuilding.nbrCdr; i += 1)
                        cdr.push_back(pack.addOtherBuilding.cdr[i]);
                    if (conf.type == PRODUCTION)
                        tempBuilding.reset(new ProdBuilding(conf, pack.addOtherBuilding.posi.get(), pack.addOtherBuilding.buildId, pack.addOtherBuilding.alegence, res.getWeaponConf(), pack.addOtherBuilding.actualHp, cdr));
                    else if (conf.type == CONSTRUCT)
                        tempBuilding.reset(new ConstructBuilding(conf, pack.addOtherBuilding.posi.get(), pack.addOtherBuilding.buildId, pack.addOtherBuilding.alegence, res.getWeaponConf(), pack.addOtherBuilding.actualHp, cdr));
                    else if (conf.type == TECH)
                        tempBuilding.reset(new TechBuilding(conf, pack.addOtherBuilding.posi.get(), pack.addOtherBuilding.buildId, pack.addOtherBuilding.alegence, res.getWeaponConf(), pack.addOtherBuilding.actualHp, cdr));
                    else
                        tempBuilding.reset(new Building(conf, pack.addOtherBuilding.posi.get(), pack.addOtherBuilding.buildId, pack.addOtherBuilding.alegence, res.getWeaponConf(), pack.addOtherBuilding.actualHp, cdr));

                    playerInfo.addOther(tempBuilding, pack.addOtherBuilding.isOther);
                }
                else if (pack.type == UPDATETARGET)
                {
                    std::shared_ptr<Unit> tempUnit = nullptr;
                    std::shared_ptr<Building> tempBuild = nullptr;
                    std::vector<std::shared_ptr<Object>> targets;
                    if (!pack.updateTarget.isBuilding && pack.updateTarget.isEnemy)
                        tempUnit = std::static_pointer_cast<Unit>(playerInfo.getOtherObject(pack.updateTarget.unitId, false));
                    else if (pack.updateTarget.isBuilding && pack.updateTarget.isEnemy)
                        tempBuild = std::static_pointer_cast<Building>(playerInfo.getOtherObject(pack.updateTarget.unitId, true));
                    if (tempBuild != nullptr || tempUnit != nullptr)
                    {
                        for (int i = 0; i < pack.updateTarget.otherLen; i += 1)
                        {
                            std::shared_ptr<Object> tempObj = playerInfo.getOtherObject(pack.updateTarget.otherId[i], pack.updateTarget.isEnemyBuilding[i]);
                            if (tempObj.get() == nullptr && !pack.updateTarget.isEnemyBuilding[i])
                                tempObj = playerInfo.getUnit(pack.updateTarget.otherId[i]);
                            else if (tempObj.get() == nullptr && pack.updateTarget.isEnemyBuilding[i])
                                tempObj = playerInfo.getBuild(pack.updateTarget.otherId[i]);
                            if (tempObj.get() == nullptr)
                                tempObj = dummy;
                            targets.push_back(tempObj);
                        }
                    }
                    if (tempUnit != nullptr)
                        playerInfo.refreshTarget(tempUnit, targets);
                    else if (tempBuild != nullptr)
                        playerInfo.refreshTarget(tempBuild, targets);
                }
            }
        }
        playerInfo.finishAction(timePassed, false);
    }
}

