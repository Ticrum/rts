// EFRITS
// project:     rts
// created on:  2024-02-13 - 16:29 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: selectBuilding implementation

#include "playerInfo.hh"

std::vector<std::shared_ptr<ef::Building>> ef::PlayerInfo::selectBuilding(Pos start,
                                                                      Pos end)
{
    Pos center;
    std::vector<std::shared_ptr<Building>> selected;

    center.x = start.x + (end.x - start.x) / 2;
    center.y = start.y + (end.y - start.y) / 2;
    for (int i = 0; i < (int)buildings.size(); i += 1)
    {
        if (center.isInRange(buildings[i]->getPos(), (end.x - start.x) / 2, (end.y - start.y) / 2) != -1)
            selected.push_back(buildings[i]);
    }
    return selected;
}

