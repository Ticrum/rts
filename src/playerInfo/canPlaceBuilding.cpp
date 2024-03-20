// EFRITS
// project:     rts
// created on:  2024-02-14 - 10:58 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: canPlaceBuilding implementation

#include "playerInfo.hh"

#include <iostream>

bool ef::PlayerInfo::canPlaceBuilding(Pos pos)
{
    for (int i = 0; i < (int)buildings.size(); i += 1)
        if (pos.isInRange(buildings[i]->getPos(), 0, 0) != -1)
            return false;
    for (int i = 0; i < (int)otherBuildings.size(); i += 1)
        if (pos.isInRange(otherBuildings[i]->getPos(), 0, 0) != -1)
            return false;
    std::cout << "PlacedBuild approuved" << std::endl;
    return true;
}

