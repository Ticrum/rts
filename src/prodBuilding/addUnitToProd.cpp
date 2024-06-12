// EFRITS
// project:     rts
// created on:  2024-02-12 - 12:21 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: addUnitToProd implementation

#include "building.hh"

void ef::ProdBuilding::addUnitToProd(ConfUnit newUnit)
{
  unitProd.push_back(newUnit);
  if (unitProd.size() == 1)
    timeLeft = unitProd[0].timeToProduce;
  needToUpdate = true;
}

