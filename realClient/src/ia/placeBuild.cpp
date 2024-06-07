// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 03/06/2024 18:14:50 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "ia.hh"

bool ef::Ia::placeBuild()
{
  std::vector<std::shared_ptr<Building>> tempBuildProd = cli.playerInfo.getProducedBuilding();
  if (MainBuild.size() <= 0)
    return false;
  Pos startPos = MainBuild[0]->getPos();
  Pos pos = startPos;
  int compt = 0;
  while (!cli.playerInfo.canPlaceBuilding(pos) && compt < 50)
    {
      pos = startPos;
      if (tempBuildProd[0]->getType() == PRODUCTION || resourceFilled)
	{
	  int dist = rand() % 2 + 2;
	  if (rand() % 2 == 1)
	    dist = -dist;
	  else
	    dist += 1;
	  pos.x += dist;

	  dist = rand() % 2 + 2;
	  if (rand() % 2 == 1)
	    dist = -dist;
	  else
	    dist += 1;
	  pos.y += dist;
	}
      else
	{
	  pos.x += rand() % 5 - 2;
	  pos.y += rand() % 5 - 2;
	}
      compt += 1;
    }
  cli.placeBuilding(pos);
  if (compt >= 50)
    return false;
  return true;
}

