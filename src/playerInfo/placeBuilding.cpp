// EFRITS
// project:     rts
// created on:  2024-02-13 - 18:08 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: placeBuilding implementation

#include "playerInfo.hh"

void ef::PlayerInfo::placeBuilding(std::shared_ptr<Building> building,
                                   bool other)
{
    if (other)
    {
        otherBuildings.push_back(building);
        buildingMap[building->getPos().x + building->getPos().y * buildingMap.getMapSize().x] = 1;
    }
    else if (canPlaceBuilding(building->getPos()))
    {
        buildings.push_back(building);
        totalEnergy += building->getEnergyProduction();
        actualEnergy += building->getEnergyProduction() - building->getEnergyCost();
        moneyGain += building->getMoneyProduction();
        buildingMap[building->getPos().x + building->getPos().y * buildingMap.getMapSize().x] = 1;
    }
}

