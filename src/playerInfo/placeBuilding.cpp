// EFRITS
// project:     rts
// created on:  2024-02-13 - 18:08 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: placeBuilding implementation

#include "playerInfo.hh"

void ef::PlayerInfo::placeBuilding(std::shared_ptr<Building> building)
{
    otherBuildings.push_back(building);
    buildingMap[building->getPos().x + building->getPos().y * buildingMap.getMapSize().x] = 1;
}

