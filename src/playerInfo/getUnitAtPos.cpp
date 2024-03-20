// EFRITS
// project:     rts
// created on:  2024-02-28 - 10:50 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: getUnitAtPos implementation

#include "playerInfo.hh"

#include <iostream>

std::shared_ptr<ef::Unit> ef::PlayerInfo::getUnitAtPos(Pos pos)
{
  std::cout << "getUnit units.size : " << units.size() << std::endl;
  for (int i = 0; i < (int)units.size(); i += 1)
    if (pos.isInRange(units[i]->getPos(), 0, 0) != -1)
      return units[i];
  std::shared_ptr<Unit> tempUnit = nullptr;
  return tempUnit;
}

