// EFRITS
// project:     rts
// created on:  2024-02-15 - 12:38 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: getConflictCell implementation

#include "pathfinder.hh"

std::shared_ptr<ef::Pathfinder::Cell> ef::Pathfinder::getConflictCell(Pos pos)
{
    std::shared_ptr<Cell> out;
    int compt;

    if (checkIndex < 2)
        compt = -checkIndex;
    else
        compt = -2;
    //printf("enter %d c = %d\n", checking.size() - checkIndex, compt);
    while (compt < ((int)checking.size() - checkIndex))
    {
        //printf("compt %d checking pos at %d %d / %d %d\n", compt, checking[checkIndex + compt]->pos.x, checking[checkIndex + compt]->pos.y, pos.x, pos.y);
        if (pos.isInRange(checking[checkIndex + compt]->pos, 0, 0) != -1)
            return checking[checkIndex + compt];
        compt += 1;
    }
    //printf("nope\n");
    out = nullptr;
    return out;
}

