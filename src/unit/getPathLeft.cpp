// EFRITS
// project:     rts
// created on:  2024-02-22 - 16:55 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: getPathLeft implementation

#include "unit.hh"

#include <iostream>

std::vector<ef::ConformPos> ef::Unit::getPathLeft()
{
    std::vector<ConformPos> tempPath;
    int start = actualIndex + 1;

    if (start > 0)
      {
	start -= 1;
	//std::cout << "getPathLeft comence not from start" << std::endl;
      }
    for(int i = start; i < (int)path.size(); i += 1)
        tempPath.push_back(path[i].get());
    return tempPath;
}

