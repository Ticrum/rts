// EFRITS
// project:     rts
// created on:  2024-02-12 - 10:43 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: moveUnit implementation

#include "unit.hh"

void ef::Unit::moveUnit(double timePassed)
{
    if (actualIndex == (int)path.size())
        return;
    if (moveType == RUN)
        progress += runningSpeed * timePassed;
    else
        progress += speed * timePassed;
    if (progress >= 1)
    {
        actualIndex += 1;
        progress = 0;
    }
}

