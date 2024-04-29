// EFRITS
// project:     rts
// created on:  2024-02-13 - 16:13 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: selectUnit implementation

#include "playerInfo.hh"

#include <iostream>

std::vector<std::shared_ptr<ef::Unit>> ef::PlayerInfo::selectUnit(Pos start,
                                                                  Pos end)
{
  Pos center;
  std::vector<std::shared_ptr<Unit>> selected;

  center.x = start.x + (end.x - start.x) / 2;
  center.y = start.y + (end.y - start.y) / 2;
  for (int i = 0; i < (int)units.size(); i += 1)
    if (center.isInRange(units[i]->getActualPos(), (end.x - start.x) / 2, (end.y - start.y) / 2) != -1)
      selected.push_back(units[i]);
  return selected;
}

