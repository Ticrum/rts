// EFRITS
// project:     rts
// created on:  2024-02-29 - 12:52 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: get implementation

#include "object.hh"

ef::Pos ef::ConformPos::get()
{
    Pos pos;

    pos.x = x;
    pos.y = y;
    return pos;
}

