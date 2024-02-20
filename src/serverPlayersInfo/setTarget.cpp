// EFRITS
// project:     rts
// created on:  2024-02-19 - 18:12 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: setTarget implementation

#include "serverPlayersInfo.hh"

void ef::ServerPlayersInfo::setTarget(int unitId,
                                      int otherId,
                                      int playerId,
                                      bool isBuilding)
{
    std::shared_ptr<Unit> unit;
    std::shared_ptr<Object> other;

    unit = getUnit(unitId, playerId);
    other = getOtherObject(otherId, playerId, isBuilding);
    if (unit.get() == nullptr)
        return;
    if (other.get() == nullptr)
        return;
    playersInfo[playerId].setTarget(unit, other);
}

