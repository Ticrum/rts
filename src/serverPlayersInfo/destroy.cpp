// EFRITS
// project:     rts
// created on:  2024-02-20 - 10:55 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: destroy implementation

#include "serverPlayersInfo.hh"

bool ef::ServerPlayersInfo::destroy(int unitId,
                                    bool isOther,
                                    int playerId,
                                    bool isBuilding)
{
    std::shared_ptr<Unit> unit;
    std::shared_ptr<Building> build;
    if (isBuilding)
    {
      build = playersInfo[playerId]->getBuild(unitId, isOther);
        return playersInfo[playerId]->destroyBuilding(build, isOther);
    }
    unit = playersInfo[playerId]->getUnit(unitId, isOther);
    return playersInfo[playerId]->destroyUnit(unit, isOther);
}

