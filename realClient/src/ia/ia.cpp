// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 03/06/2024 15:56:15 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "ia.hh"

ef::Ia::Ia(double playerAtracted,
	   double agressive,
	   double teamPlayer,
	   double protecting,
	   ClientPlayerInfo & _cli,
	   std::function<void(std::string)> _singleCommand,
	   Pos _size)
  :
  brain(playerAtracted, agressive, teamPlayer, protecting),
  nbrMoneyP(0),
  nbrProd(0),
  unitToProd(-1),
  internalEnergy(200),
  mapSize(64),
  resourceFilled(false),
  pressureMap(mapSize.x, mapSize.y),
  cli(_cli),
  size(_size),
  singleCommand(_singleCommand)
{
}

