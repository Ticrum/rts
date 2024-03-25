#include "unit.hh"

std::vector<ef::ConformPos> ef::Unit::getPartPath()
{
    std::vector<ConformPos> tempPath;
    if (actualIndex == 0 || actualIndex + 1 == path.size())
      tempPath.push_back(pos.get());
    else
      tempPath.push_back(path[actualIndex - 1].get());
    tempPath.push_back(path[actualIndex].get());
    return tempPath;
}
