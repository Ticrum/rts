// EFRITS
// project:     rts
// created on:  2024-02-29 - 12:54 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: get implementation

#include "object.hh"

ef::ConformPos ef::Pos::get()
{
    ConformPos pos;

    pos.x = x;
    pos.y = y;
    return pos;
}

