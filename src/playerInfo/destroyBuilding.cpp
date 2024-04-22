// EFRITS
// project:     rts
// created on:  2024-02-13 - 12:30 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: destroyBuilding implementation

#include "playerInfo.hh"

#include <iostream>

bool ef::PlayerInfo::destroyBuilding(std::shared_ptr<Building> building,
                                     bool isOther)
{
  int len;

  if (isOther)
    len = otherBuildings.size();
  else
    len = buildings.size();
  for (int i = 0; i < len; i += 1)
    {
      if (isOther)
        {
	  if (otherBuildings[i]->getId() == building->getId())
            {
	      std::cout << "destroyBuilding PASS OTHER" << std::endl;
	      otherBuildings[i] = otherBuildings[otherBuildings.size() - 1];
	      otherBuildings[otherBuildings.size() - 1] = building;
	      buildingMap[building->getPos().x + building->getPos().y * buildingMap.getMapSize().x] = 0;
	      otherBuildings.pop_back();
	      return true;
            }
        }
      else if (buildings[i]->getId() == building->getId())
        {
	  std::cout << "destroyBuilding PASS NOT OTHER" << std::endl;
	  buildings[i] = buildings[buildings.size() - 1];
	  buildings[buildings.size() - 1] = building;
	  totalEnergy -= building->getEnergyProduction();
	  actualEnergy -= building->getEnergyProduction() - building->getEnergyCost();
	  moneyGain -= building->getMoneyProduction();
	  buildingMap[building->getPos().x + building->getPos().y * buildingMap.getMapSize().x] = 0;
	  buildings.pop_back();
	  return true;
        }
    }
  return false;
}

