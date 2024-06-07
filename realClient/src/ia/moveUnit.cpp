// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/06/2024 12:21:54 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "ia.hh"

void ef::Ia::moveUnit()
{
  if (unitToProd == 0)
    {
      Pos pos[2];
      pos[0].x = 0;
      pos[0].y = 0;
      pos[1].x = mapSize.x;
      pos[1].y = mapSize.y;

      cli.select(size, pos[0], pos[1], singleCommand, false);
      std::vector<std::shared_ptr<Unit>> & tempUnit = cli.playerInfo.getOtherUnits();
      std::vector<std::shared_ptr<Building>> & tempBuilding = cli.playerInfo.getOtherBuild();
      pos[0].x = mapSize.x / 2;
      pos[0].y = mapSize.y / 2;
      if (tempUnit.size() > 0)
	pos[0] = tempUnit[0]->getActualPos();
      else if (tempBuilding.size() > 0)
	pos[0] = tempBuilding[0]->getPos();
      cli.makePath(pos[0], WALK);
      if (unitToProd == 0)
	{
	  unitToProd = -1;
	  if (resourceFilled)
	    nbrMoneyP = 5;
	  else
	    nbrMoneyP = 0;
	}
    }
}

