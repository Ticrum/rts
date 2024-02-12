// EFRITS
// project:     rts
// created on:  2024-02-12 - 16:13 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: addSearchToList implementation

#include "building.hh"

void ef::TechBuilding::addSearchToList(Tech newSearch)
{
    techResearch.push_back(newSearch);
}

