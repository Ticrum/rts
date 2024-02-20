// EFRITS
// project:     rts
// created on:  2024-02-16 - 12:21 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: addBuildingToProd implementation

#include "building.hh"

void ef::ConstructBuilding::addBuildingToProd(ConfBuilding newBuilding)
{
    buildingProd.push_back(newBuilding);
}

