// EFRITS
// project:     rts
// created on:  2024-02-13 - 16:29 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: selectBuilding implementation

#include "playerInfo.hh"

std::vector<std::shared_ptr<ef::Building>> ef::PlayerInfo::selectBuilding(Pos start,
									  Pos end)
{
  std::vector<std::shared_ptr<Building>> selected;

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

  for (int i = 0; i < (int)buildings.size(); i += 1)
    if (buildings[i]->getPos().x >= start.x && buildings[i]->getPos().y >= start.y &&
	buildings[i]->getPos().x <= end.x && buildings[i]->getPos().y <= end.y)
      selected.push_back(buildings[i]);
  return selected;
}

