// EFRITS
// project:     rts
// created on:  2024-02-13 - 11:29 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: produce implementation

#include "playerInfo.hh"

#include <iostream>

bool ef::PlayerInfo::produce(std::shared_ptr<ProdBuilding> producer,
                             ConfUnit newUnit)
{
  //std::cout << "passed in produced unit" << std::endl;
  if (money < newUnit.cost)
    {
      std::cout << "YOU HAVE NO MONEY" << std::endl;
      return false;
    }
  money -= newUnit.cost;
  producer->addUnitToProd(newUnit);
  return true;
}

