// EFRITS
// project:     rts
// created on:  2024-02-13 - 17:14 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: computeShot implementation

#include "playerInfo.hh"

#include <iostream>

void ef::PlayerInfo::computeShot(bool isClient)
{
  std::vector<std::shared_ptr<Object>> tempObj;

  //std::cout << "COUCOU in computeShot" << std::endl;
  for (int i = 0; i < (int)units.size(); i += 1)
    tempObj.push_back(units[i]);
  for (int i = 0; i < (int)otherShots.size(); i += 1)
    otherShots[i]->kaboom(tempObj, false);
  tempObj.clear();
  for (int i = 0; i < (int)buildings.size(); i += 1)
    tempObj.push_back(buildings[i]);
  for (int i = 0; i < (int)otherShots.size(); i += 1)
    otherShots[i]->kaboom(tempObj, true);
  tempObj.clear();
  if (isClient)
    {
      for (int i = 0; i < (int)otherUnits.size(); i += 1)
	tempObj.push_back(otherUnits[i]);
      for (int i = 0; i < (int)shots.size(); i += 1)
	shots[i]->kaboom(tempObj, false);
      tempObj.clear();
      for (int i = 0; i < (int)otherBuildings.size(); i += 1)
	tempObj.push_back(otherBuildings[i]);
      for (int i = 0; i < (int)shots.size(); i += 1)
	shots[i]->kaboom(tempObj, true);
    }
  shots.clear();
  otherShots.clear();
  for (int i = 0; i < (int)buildings.size(); i += 1)
    if (buildings[i]->getHp() <= 0)
      {
	std::cout << "build is dead" << std::endl;
	Killed tempKill;
	tempKill.obj = buildings[i];
	tempKill.time = 0;
	tempKill.isOther = false;
	killList.push_back(tempKill);
	destroyBuilding(buildings[i], false);
      }
  for (int i = 0; i < (int)units.size(); i += 1)
    if (units[i]->getHp() <= 0)
      {
	std::cout << "unit is dead" << std::endl;
	Killed tempKill;
	tempKill.obj = units[i];
	tempKill.time = 0;
	tempKill.isOther = false;
	killList.push_back(tempKill);
	destroyUnit(units[i], false);
      }
}
