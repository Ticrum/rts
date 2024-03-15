// EFRITS
// project:     rts
// created on:  2024-02-16 - 12:21 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: addBuildingToProd implementation

#include "building.hh"

#include <iostream>

void ef::ConstructBuilding::addBuildingToProd(ConfBuilding newBuilding)
{
  std::cout << "before : " << newBuilding.conf << " size : " << this << std::endl;
  buildingProd.push_back(newBuilding);
  std::cout << "after" << std::endl;
}

