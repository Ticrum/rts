// EFRITS
// project:     rts
// created on:  2024-02-14 - 11:39 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: makePath implementation

#include "playerInfo.hh"

void ef::PlayerInfo::makePath(std::shared_ptr<Unit> unit,
                              Pos dest,
                              MoveType moveType)
{
    path.resetMap(buildingMap);
    unit->changePath(path.makePath(unit->getPos(), dest), moveType);
}

