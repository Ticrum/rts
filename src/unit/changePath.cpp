// EFRITS
// project:     rts
// created on:  2024-02-12 - 11:09 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: changePath implementation

#include "unit.hh"

#include <iostream>

void ef::Unit::changePath(std::vector<Pos> newPath,
                          MoveType type)
{
  std::cout << "change path size : " << newPath.size() << std::endl;
  if (path.size() > 0)
    {
      std::cout << "change path reset" << std::endl;
      if (actualIndex > 0)
	pos = path[actualIndex - 1];
      path.clear();
    }
  progress = 0;
  actualIndex = 0;
  for (int i = newPath.size() - 1; i >= 0; i -= 1)
    path.push_back(newPath[i]);
  //path = newPath;
  moveType = type;
}

