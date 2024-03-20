// EFRITS
// project:     rts
// created on:  2024-02-12 - 10:43 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: moveUnit implementation

#include "unit.hh"

#include <iostream>

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
      std::cout << "||||||||HAS MOVED FOWARD|||||||| " << actualIndex << " : " << path.size() << std::endl;
      std::cout << "NOW AT pos x : " << path[actualIndex - 1].x << " y : " << path[actualIndex - 1].y << std::endl;
      actualIndex += 1;
      progress = 0;
    }
}

