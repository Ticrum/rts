// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 23/05/2024 17:17:37 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "building.hh"

void ef::TechBuilding::cancelTech(int & money)
{
  if ((int)techResearch.size() <= 0)
    return;
  money += techResearch[0].cost;
  std::vector<Tech> tempVect = techResearch;
  techResearch.clear();
  for (int i = 0; i < (int)tempVect.size() - 1; i += 1)
    techResearch.push_back(tempVect[i + 1]);
  if (techResearch.size() > 0)
    timeLeft = techResearch[0].timeToSearch;
  else
    timeLeft = 0;
}

