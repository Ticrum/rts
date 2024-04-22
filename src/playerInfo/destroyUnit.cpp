// EFRITS
// project:     rts
// created on:  2024-02-13 - 12:10 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: destroyUnit implementation

#include "playerInfo.hh"

#include <iostream>

bool ef::PlayerInfo::destroyUnit(std::shared_ptr<Unit> unit,
                                 bool isOther)
{
  int len;

  if (isOther)
    len = otherUnits.size();
  else
    len = units.size();
  for (int i = 0; i < len; i += 1)
    {
      if (isOther)
        {
	  if (otherUnits[i]->getId() == unit->getId())
            {
	      std::cout << "destroyUnit PASS OTHER" << std::endl;
	      otherUnits[i] = otherUnits[otherUnits.size() - 1];
	      otherUnits[otherUnits.size() - 1] = unit;
	      otherUnits.pop_back();
	      return true;
            }
        }
      else if (units[i]->getId() == unit->getId())
        {
	  std::cout << "destroyUnit PASS NOT OTHER" << std::endl;
	  units[i] = units[units.size() - 1];
	  units[units.size() - 1] = unit;
	  units.pop_back();
	  return true;
        }
    }
  return false;
}

