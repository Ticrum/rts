// EFRITS
// project:     rts
// created on:  2024-02-22 - 11:25 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: updateOther implementation

#include "playerInfo.hh"

void ef::PlayerInfo::updateOther()
{
    std::vector<std::shared_ptr<Unit>> tempOtherUnit;
    for (int i = 0; i < (int)otherUnits.size(); i += 1)
        if (isInVision(otherUnits[i]))
            tempOtherUnit.push_back(otherUnits[i]);
    otherUnits = tempOtherUnit;
    std::vector<std::shared_ptr<Building>> tempOtherBuilding;
    for (int i = 0; i < (int)otherBuildings.size(); i += 1)
        if (isInVision(otherBuildings[i]))
            tempOtherBuilding.push_back(otherBuildings[i]);
    otherBuildings = tempOtherBuilding;
}

