// EFRITS
// project:     rts
// created on:  2024-02-19 - 17:51 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: makePath implementation

#include "serverPlayersInfo.hh"

void ef::ServerPlayersInfo::makePath(int unitId,
                                     Pos dest,
                                     MoveType moveType,
                                     int playerId)
{
    std::shared_ptr<Unit> unit;

    unit = playersInfo[playerId].getUnit(unitId);
    if (unit.get() == nullptr)
        return;
    playersInfo[playerId].makePath(unit, dest, moveType);
}

