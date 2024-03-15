// EFRITS
// project:     rts
// created on:  2024-02-16 - 17:07 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: produce3 implementation

#include "playerInfo.hh"

#include <iostream>

bool ef::PlayerInfo::produce(std::shared_ptr<ConstructBuilding> producer,
                             ConfBuilding newBuilding)
{
  std::cout << "passed in produced build" << std::endl;
  if (money < newBuilding.cost)
    {
      std::cout << "YOU HAVE NO MONEY" << std::endl;
      return false;
    }
  money -= newBuilding.cost;
  producer->addBuildingToProd(newBuilding);
  std::cout << "still good from now" << std::endl;
  return true;
}

