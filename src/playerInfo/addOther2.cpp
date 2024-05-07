// EFRITS
// project:     rts
// created on:  2024-02-13 - 12:41 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: addOther2 implementation

#include "playerInfo.hh"

void ef::PlayerInfo::addOther(std::shared_ptr<Building> building,
                              bool isOther)
{
  if (isOther)
    otherBuildings.push_back(building);
  else
    {
      buildings.push_back(building);
      totalEnergy += building->getEnergyProduction();
      actualEnergy += building->getEnergyProduction() - building->getEnergyCost();
      moneyGain += building->getMoneyProduction();
    }
  buildingMap[building->getPos().x + building->getPos().y * buildingMap.getMapSize().x] = 1;
}

