// EFRITS
// project:     rts
// created on:  2024-02-22 - 16:55 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: getPathLeft implementation

#include "unit.hh"

std::vector<ef::ConformPos> ef::Unit::getPathLeft()
{
    std::vector<ConformPos> tempPath;

    for(int i = actualIndex; i < (int)tempPath.size(); i += 1)
        tempPath.push_back(path[i].get());
    return tempPath;
}

