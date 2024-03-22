// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 15/03/2024 17:03:28 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "playerInfo.hh"

void ef::PlayerInfo::updateVisionMap()
{
  for (int i = 0; i < (int)units.size(); i += 1)
    for (int x = units[i]->getActualPos().x - units[i]->getRangeOfVision(); x <= units[i]->getActualPos().x + units[i]->getRangeOfVision(); x += 1)
      for (int y = units[i]->getActualPos().y - units[i]->getRangeOfVision(); y <= units[i]->getActualPos().y + units[i]->getRangeOfVision(); y += 1)
	if (x >= 0 && x < visionMap.getMapSize().x && y >= 0 && y < visionMap.getMapSize().y)
	  visionMap[x + y * visionMap.getMapSize().x] = 3;
  for (int i = 0; i < (int)buildings.size(); i += 1)
    for (int x = buildings[i]->getPos().x - buildings[i]->getRangeOfVision(); x <= buildings[i]->getPos().x + buildings[i]->getRangeOfVision(); x += 1)
      for (int y = buildings[i]->getPos().y - buildings[i]->getRangeOfVision(); y <= buildings[i]->getPos().y + buildings[i]->getRangeOfVision(); y += 1)
	if (x >= 0 && x < visionMap.getMapSize().x && y >= 0 && y < visionMap.getMapSize().y)
	  visionMap[x + y * visionMap.getMapSize().x] = 3;
  for (int i = 0; i < visionMap.getMapSize().x * visionMap.getMapSize().y; i += 1)
    {
      if (visionMap[i] == 2)
	visionMap[i] = 1;
      else if (visionMap[i] == 3)
	visionMap[i] = 2;
    }
  //visionMap[visionMap.getMapSize().x - 6 + 5 * visionMap.getMapSize().x] = 9;
}

