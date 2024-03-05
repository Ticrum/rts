// EFRITS
// project:     rts
// created on:  2024-02-13 - 17:14 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: finishAction implementation

#include "playerInfo.hh"

std::vector<std::shared_ptr<ef::Object>> ef::PlayerInfo::finishAction(double timePassed)
{
  std::vector<std::shared_ptr<Object>> tempShot;

  for (int i = 0; i < (int)buildings.size(); i += 1)
    {
      tempShot = buildings[i]->fireAllWeapon(timePassed);
      for (int j = 0; j < (int)tempShot.size(); j += 1)
	shots.push_back(tempShot[j]);
    }
  for (int i = 0; i < (int)units.size(); i += 1)
    {
      tempShot = units[i]->fireAllWeapon(timePassed);
      for (int j = 0; j < (int)tempShot.size(); j += 1)
	shots.push_back(tempShot[j]);
    }
  return shots;
}

