// EFRITS
// project:     rts
// created on:  2024-02-12 - 15:24 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: searchTech implementation

#include "building.hh"

std::shared_ptr<ef::Tech> ef::TechBuilding::searchTech(double timePassed)
{
    std::shared_ptr<Tech> newTech;

    if (!onHold)
        timeLeft -= timePassed;
    if (timeLeft <= 0)
    {
        //newTech.reset(new Tech());
        newTech->techName = techResearch[0].techName;
        newTech->isSearched = true;
        std::vector<Tech> tempVect = techResearch;
        techResearch.resize(techResearch.size() - 1);
        for (int i = 0; i < (int)techResearch.size(); i += 1)
            techResearch[i] = tempVect[i + 1];
    }
    else
        newTech = nullptr;
    return newTech;
}

