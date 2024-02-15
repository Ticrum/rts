// EFRITS
// project:     rts
// created on:  2024-02-12 - 18:18 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: isInRange implementation

#include "object.hh"

int ef::Pos::isInRange(ef::Pos other, int _x, int _y)
{
    if (other.x >= x - _x && other.x <= x + _x && other.y >= y - _y && other.y <= y + _y)
    {
        int xdist = other.x - x;
        int ydist = other.y - y;
        return xdist * xdist + ydist * ydist;
    }
    return -1;
}

