// EFRITS
// project:     rts
// created on:  2024-02-09 - 10:55 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: setPos implementation

#include "object.hh"

void ef::Object::setPos(int x, int y)
{
    pos.x = x;
    pos.y = y;
}

