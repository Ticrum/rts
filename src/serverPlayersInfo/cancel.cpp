// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 23/05/2024 18:17:16 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "serverPlayersInfo.hh"

void ef::ServerPlayersInfo::cancel(int producerId,
				   int playerId,
				   BuildingType type)
{
  std::shared_ptr<Building> build = playersInfo[playerId]->getBuild(producerId, false);
  if (type == PRODUCTION)
    {
      std::shared_ptr<ProdBuilding> pBuild = std::static_pointer_cast<ProdBuilding>(build);
      playersInfo[playerId]->cancel(pBuild);
    }
  else if (type == CONSTRUCT)
    {
      std::shared_ptr<ConstructBuilding> cBuild = std::static_pointer_cast<ConstructBuilding>(build);
      playersInfo[playerId]->cancel(cBuild);
    }
  else if (type == TECH)
    {
      std::shared_ptr<TechBuilding> tBuild = std::static_pointer_cast<TechBuilding>(build);
      playersInfo[playerId]->cancel(tBuild);
    }
}

