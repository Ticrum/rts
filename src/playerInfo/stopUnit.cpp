// EFRITS
// project:     rts
// created on:  2024-02-12 - 17:28 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: stopUnit implementation

#include "playerInfo.hh"

void ef::PlayerInfo::stopUnit(std::shared_ptr<Unit> unit)
{
    std::vector<Pos> path;
    unit->changePath(path, STATIC);
}

