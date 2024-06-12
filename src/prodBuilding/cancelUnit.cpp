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

void ef::ProdBuilding::cancelUnit(int & money)
{
  if ((int)unitProd.size() <= 0)
    return;
  money += unitProd[0].cost;
  std::vector<ConfUnit> tempVect = unitProd;
  unitProd.clear();
  for (int i = 0; i < (int)tempVect.size() - 1; i += 1)
    unitProd.push_back(tempVect[i + 1]);
  if (unitProd.size() > 0)
    timeLeft = unitProd[0].timeToProduce;
  else
    timeLeft = 0;
}

