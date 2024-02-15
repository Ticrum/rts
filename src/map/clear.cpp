// EFRITS
// project:     rts
// created on:  2024-02-14 - 12:11 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: clear implementation

#include "map.hh"

void ef::Map::clear(char data)
{
    for (int i = 0; i < mapSize.x * mapSize.y; i += 1)
        map[i] = data;
}

