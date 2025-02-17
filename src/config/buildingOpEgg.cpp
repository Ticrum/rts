// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 26/04/2024 11:53:48 ******************************************************
// romain.piccoche <romain.picoche@laika.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "building.hh"

ef::ConfBuilding &ef::ConfBuilding::operator=(ConfBuilding const&other)
{
  cost = other.cost;
  timeToProduce = other.timeToProduce;
  type = other.type;
  canBeTarget = other.canBeTarget;
  energyCost = other.energyCost;
  energyProduction = other.energyProduction;
  moneyProduction = other.moneyProduction;
  butons = other.butons;
  weaponConf = other.weaponConf;
  ConfObj::operator =(other);
  return *this;
}
