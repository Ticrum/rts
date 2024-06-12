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
  std::vector<std::shared_ptr<Unit>> selected;

  if (start.x > end.x)
    {
      int temp = start.x;
      start.x = end.x;
      end.x = temp;
    }
  if (start.y > end.y)
    {
      int temp = start.y;
      start.y = end.y;
      end.y = temp;
    }

  for (int i = 0; i < (int)units.size(); i += 1)
    if (units[i]->getActualPos().x >= start.x && units[i]->getActualPos().y >= start.y &&
	units[i]->getActualPos().x <= end.x && units[i]->getActualPos().y <= end.y)
      selected.push_back(units[i]);
  return selected;
}

