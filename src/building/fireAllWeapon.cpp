// EFRITS
// project:     rts
// created on:  2024-02-12 - 11:40 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: fireAllWeapon implementation

#include "building.hh"

std::vector<std::shared_ptr<ef::Object>> ef::Building::fireAllWeapon(double timePassed)
{
  std::vector<std::shared_ptr<Object>> shots;
  std::shared_ptr<Object> tempObj = nullptr;

  for (int i = 0; i < (int)weapons.size(); i += 1)
    if ((tempObj = weapons[i].fireAction(timePassed)) != nullptr)
      shots.push_back(tempObj);
  return shots;
}

