// EFRITS
// project:     rts
// created on:  2024-02-20 - 16:57 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: getBuild implementation

#include "playerInfo.hh"

std::shared_ptr<ef::Building> ef::PlayerInfo::getBuild(int buildId,
						       bool isOther)
{
  if (isOther)
    {
      for (int i = 0; i < (int)otherBuildings.size(); i += 1)
	if (otherBuildings[i]->getId() == buildId)
	  return otherBuildings[i];
    }
  else
    for (int i = 0; i < (int)buildings.size(); i += 1)
      if (buildings[i]->getId() == buildId)
	return buildings[i];
  std::shared_ptr<Building> temp = nullptr;
  return temp;
}

