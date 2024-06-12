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

void ef::ConstructBuilding::cancelBuilding(int & money)
{
  if ((int)buildingProd.size() <= 0)
    return;
  money += buildingProd[0].cost;
  std::vector<ConfBuilding> tempVect = buildingProd;
  buildingProd.clear();
  for (int i = 0; i < (int)tempVect.size() - 1; i += 1)
    buildingProd.push_back(tempVect[i + 1]);
  if (buildingProd.size() > 0)
    timeLeft = buildingProd[0].timeToProduce;
  else
    timeLeft = 0;
}

