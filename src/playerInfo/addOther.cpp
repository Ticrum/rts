// EFRITS
// project:     rts
// created on:  2024-02-13 - 12:38 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: addOther implementation

#include "playerInfo.hh"

#include <iostream>

void ef::PlayerInfo::addOther(std::shared_ptr<Unit> unit,
                              bool isOther)
{
  if (isOther)
    {
      otherUnits.push_back(unit);
      std::cout << "addOtherUnit add pass size : " << otherUnits.size() << std::endl;
    }
  else
    units.push_back(unit);
}

