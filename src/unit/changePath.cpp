// EFRITS
// project:     rts
// created on:  2024-02-12 - 11:09 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: changePath implementation

#include "unit.hh"

void ef::Unit::changePath(std::vector<Pos> newPath,
                          MoveType type)
{
    path = newPath;
    moveType = type;
}

