// EFRITS
// project:     rts
// created on:  2024-02-28 - 10:59 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: getBuildingAtPos implementation

#include "playerInfo.hh"

std::shared_ptr<ef::Building> ef::PlayerInfo::getBuildingAtPos(Pos pos)
{
    for (int i = 0; i < (int)buildings.size(); i += 1)
        if (pos.isInRange(buildings[i]->getPos(), 0, 0) != -1)
            return buildings[i];
    std::shared_ptr<Building> tempBuilding = nullptr;
    return tempBuilding;
}

