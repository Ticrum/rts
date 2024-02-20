// EFRITS
// project:     rts
// created on:  2024-02-19 - 18:06 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: stopUnit implementation

#include "serverPlayersInfo.hh"

void ef::ServerPlayersInfo::stopUnit(int unitId,
                                     int playerId)
{
    std::shared_ptr<Unit> unit;

    unit = getUnit(unitId, playerId);
    if (unit.get() == nullptr)
        return;
    playersInfo[playerId].stopUnit(unit);
}

