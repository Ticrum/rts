// EFRITS
// project:     rts
// created on:  2024-02-22 - 12:40 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: getUnitInVision implementation

#include "playerInfo.hh"

std::vector<std::shared_ptr<ef::Unit>> ef::PlayerInfo::getUnitInVision(Map vision)
{
    std::vector<std::shared_ptr<Unit>> unitSeen;
    for (int i = 0; i < (int)units.size(); i += 1)
        if (vision[units[i]->getActualPos().x + units[i]->getActualPos().y * vision.getMapSize().x] == 2)
            unitSeen.push_back(units[i]);
    return unitSeen;
}

