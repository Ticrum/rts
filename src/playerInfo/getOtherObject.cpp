// EFRITS
// project:     rts
// created on:  2024-02-20 - 17:14 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: getOtherObject implementation

#include "playerInfo.hh"

std::shared_ptr<ef::Object> ef::PlayerInfo::getOtherObject(int otherId,
                                                       bool isBuilding)
{
    std::shared_ptr<Object> temp = nullptr;
    if (isBuilding)
    {
        for (int i = 0; i < (int)otherBuildings.size(); i += 1)
            if (otherBuildings[i]->getId() == otherId)
                temp = otherBuildings[i];
    }
    else
        for (int i = 0; i < (int)otherUnits.size(); i += 1)
            if (otherUnits[i]->getId() == otherId)
                temp = otherUnits[i];
    return temp;
}

