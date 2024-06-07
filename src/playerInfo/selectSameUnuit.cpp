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

std::vector<std::shared_ptr<ef::Unit>> ef::PlayerInfo::selectSameUnit(Pos start,
								      Pos end)
{
  std::vector<std::shared_ptr<Unit>> selected;
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

  for (int i = 0; i < (int)units.size(); i += 1)
    if (units[i]->getActualPos().x >= start.x && units[i]->getActualPos().y >= start.y &&
	units[i]->getActualPos().x <= end.x && units[i]->getActualPos().y <= end.y)
      {
	selected.push_back(units[i]);
	selectedConf = units[i]->getConf();
	selectedIndex = i;
	i = units.size() + 1;
      }
  for (int i = 0; i < (int)units.size(); i += 1)
    if (selectedConf == units[i]->getConf() && i != selectedIndex)
      selected.push_back(units[i]);
  return selected;
}

