// EFRITS
// project:     rts
// created on:  2024-02-22 - 11:25 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: updateOther implementation

#include "playerInfo.hh"

#include <iostream>

void ef::PlayerInfo::increaseUpdateIndex()
{
  //std::cout << "increaseUpdateIndex otherUnitUpdaterIndex = " << otherUnitUpdaterIndex << " otherUnits.size() = " << otherUnits.size() << std::endl;
  otherUnitUpdaterIndex += 1;
  if (otherUnitUpdaterIndex >= otherUnits.size())
    otherUnitUpdaterIndex = 0;
}


