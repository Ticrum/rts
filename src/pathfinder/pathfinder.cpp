// EFRITS
// project:     rts
// created on:  2024-02-14 - 15:40 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: pathfinder implementation

#include "pathfinder.hh"

ef::Pathfinder::Pathfinder(Map & baseMap)
    :
    map(baseMap.getMapSize().x, baseMap.getMapSize().y),
    checkIndex(0)
{
    resetMap(baseMap);
}

