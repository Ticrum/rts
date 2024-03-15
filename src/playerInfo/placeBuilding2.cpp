// EFRITS
// project:     rts
// created on:  2024-02-16 - 11:09 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: placeBuilding2 implementation

#include "playerInfo.hh"

std::shared_ptr<ef::Building> ef::PlayerInfo::placeBuilding(Pos pos)
{
  std::shared_ptr<ef::Building> tempBuild = nullptr;
  if (canPlaceBuilding(pos) && (int)producedBuilding.size() > 0)
    {
      buildings.push_back(producedBuilding[0]);
      totalEnergy += producedBuilding[0]->getEnergyProduction();
      actualEnergy += producedBuilding[0]->getEnergyProduction() - producedBuilding[0]->getEnergyCost();
      moneyGain += producedBuilding[0]->getMoneyProduction();
      tempBuild = producedBuilding[0];
      buildingMap[pos.x + pos.y * buildingMap.getMapSize().x] = 1;
      producedBuilding[0]->setPos(pos.x, pos.y);
      std::vector<std::shared_ptr<Building>> temp = producedBuilding;
      producedBuilding.clear();
      for (int i = 0; i < (int)temp.size() - 1; i += 1)
	producedBuilding.push_back(temp[i + 1]);
    }
  return tempBuild;
}

