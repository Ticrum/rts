// EFRITS
// project:     rts
// created on:  2024-02-16 - 12:07 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: produceBuilding implementation

#include "building.hh"

std::shared_ptr<ef::Building> ef::ConstructBuilding::produceBuilding(double timePassed,
								     std::vector<ConfWeapon> & weaponsConf,
								     std::map<std::string, std::shared_ptr<Bpixelarray>> &imgs)
{
  std::shared_ptr<Building> newBuilding;

  if (!onHold)
    timeLeft -= timePassed;
  if (timeLeft <= 0)
    {
      if (buildingProd.size() > 0)
        {
	  Pos tempPos = getPos();
	  tempPos.x += 1;
	  newBuilding.reset(new Building(buildingProd[0], imgs[buildingProd[0].img], tempPos, rand(), alegence, weaponsConf));
	  std::vector<ConfBuilding> tempVect = buildingProd;
	  buildingProd.clear();
	  for (int i = 0; i < (int)tempVect.size() - 1; i += 1)
	    buildingProd.push_back(tempVect[i + 1]);
	  if (buildingProd.size() > 0)
	    timeLeft = buildingProd[0].timeToProduce;
        }
    }
  else
    newBuilding = nullptr;
  return newBuilding;
}

