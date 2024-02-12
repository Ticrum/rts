// EFRITS
// project:     rts
// created on:  2024-02-12 - 17:08 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: operator_crochet implementation

#include "map.hh"

char & ef::Map::operator[](int index)
{
    return map[index];
}

