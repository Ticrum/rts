// EFRITS
// project:     rts
// created on:  2024-02-14 - 15:51 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: resetMap implementation

#include "pathfinder.hh"

void ef::Pathfinder::resetMap(Map & baseMap)
{
    for (int i = 0; i < baseMap.getMapSize().x * baseMap.getMapSize().y; i += 1)
    {
        if (baseMap[i] != 0)
            map[i] = 1;
        else
            map[i] = 0;
    }
}

