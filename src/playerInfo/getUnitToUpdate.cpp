// EFRITS
// project:     rts
// created on:  2024-02-22 - 11:25 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: updateOther implementation

#include "playerInfo.hh"

std::shared_ptr<ef::Unit> ef::PlayerInfo::getUnitToUpdate()
{
  if (otherUnits.size() > 0)
    return (otherUnits[otherUnitUpdaterIndex]);
  std::shared_ptr<Unit> temp = nullptr;
  return temp;
}

