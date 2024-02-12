// EFRITS
// project:     rts
// created on:  2024-02-12 - 17:03 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: map implementation

#include "map.hh"

ef::Map::Map(int sizex, int sizey)
{
    map.resize(sizex * sizey);
    mapSize.x = sizex;
    mapSize.y = sizey;
}

