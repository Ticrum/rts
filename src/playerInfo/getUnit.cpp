// EFRITS
// project:     rts
// created on:  2024-02-20 - 16:39 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: getUnit implementation

#include "playerInfo.hh"

std::shared_ptr<ef::Unit> ef::PlayerInfo::getUnit(int unitId,
						  bool isOther)
{
  if (isOther)
    {
      for (int i = 0; i < (int)otherUnits.size(); i += 1)
        if (otherUnits[i]->getId() == unitId)
	  return otherUnits[i];
    }
  else
    for (int i = 0; i < (int)units.size(); i += 1)
      if (units[i]->getId() == unitId)
	return units[i];
  std::shared_ptr<Unit> temp = nullptr;
  return temp;
}

