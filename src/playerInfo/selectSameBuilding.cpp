// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 28/05/2024 16:53:09 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "playerInfo.hh"

std::vector<std::shared_ptr<ef::Building>> ef::PlayerInfo::selectSameBuilding(Pos start,
									      Pos end)
{
  std::vector<std::shared_ptr<Building>> selected;
  std::string selectedConf;
  int selectedIndex = -1;

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
      {
	selected.push_back(buildings[i]);
	selectedConf = buildings[i]->getConf();
	selectedIndex = i;
	i = buildings.size() + 1;
      }
  for (int i = 0; i < (int)buildings.size(); i += 1)
    if (selectedConf == buildings[i]->getConf() && i != selectedIndex)
      selected.push_back(buildings[i]);
  return selected;
}

