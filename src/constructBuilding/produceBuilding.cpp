// EFRITS
// project:     rts
// created on:  2024-02-16 - 12:07 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: produceBuilding implementation

#include "building.hh"

#include <iostream>

std::shared_ptr<ef::Building> ef::ConstructBuilding::produceBuilding(double timePassed,
								     std::vector<ConfWeapon> & weaponsConf,
								     std::vector<ConfObj> & shotConf,
								     std::map<std::string, std::shared_ptr<Bpixelarray>> &imgs)
{
  std::shared_ptr<Building> newBuilding;

  if (!onHold && timeLeft > 0)
    {
      timeLeft -= timePassed;
      //std::cout << "produceBuilding pass time : " << std::endl;
    }
  if (timeLeft <= 0)
    {
      //std::cout << "buildProdSize : " << buildingProd.size() << std::endl;
      if (buildingProd.size() > 0)
        {
	  Pos tempPos = getPos();
	  tempPos.x += 1;
	  if (buildingProd[0].type == PRODUCTION)
	    newBuilding.reset(new ProdBuilding(buildingProd[0], imgs[buildingProd[0].img], tempPos, rand(), alegence, weaponsConf, shotConf));
	  else if (buildingProd[0].type == CONSTRUCT)
	    newBuilding.reset(new ConstructBuilding(buildingProd[0], imgs[buildingProd[0].img], tempPos, rand(), alegence, weaponsConf, shotConf));
	  else if (buildingProd[0].type == TECH)
	    newBuilding.reset(new TechBuilding(buildingProd[0], imgs[buildingProd[0].img], tempPos, rand(), alegence, weaponsConf, shotConf));
	  else
	    newBuilding.reset(new Building(buildingProd[0], imgs[buildingProd[0].img], tempPos, rand(), alegence, weaponsConf, shotConf));
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

