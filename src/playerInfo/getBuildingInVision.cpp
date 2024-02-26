// EFRITS
// project:     rts
// created on:  2024-02-22 - 12:32 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: getBuildingInVision implementation

#include "playerInfo.hh"

std::vector<std::shared_ptr<ef::Building>> ef::PlayerInfo::getBuildingInVision(Map vision)
{
    std::vector<std::shared_ptr<Building>> buildingSeen;
    for (int i = 0; i < (int)buildings.size(); i += 1)
        if (vision[buildings[i]->getPos().x + buildings[i]->getPos().y * vision.getMapSize().x] == 2)
            buildingSeen.push_back(buildings[i]);
    return buildingSeen;
}

