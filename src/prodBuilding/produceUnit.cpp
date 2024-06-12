// EFRITS
// project:     rts
// created on:  2024-02-12 - 12:24 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: produceUnit implementation

#include "building.hh"

#include <iostream>

std::shared_ptr<ef::Unit> ef::ProdBuilding::produceUnit(double timePassed,
                                                        std::vector<ConfWeapon> & weaponsConf,
                                                        std::vector<ConfObj> & shotConf,
							std::map<std::string, std::shared_ptr<Bpixelarray>> & imgs)
{
  std::shared_ptr<Unit> newUnit;

  if (!onHold && timeLeft > 0)
    timeLeft -= timePassed;
  //std::cout << "produce unit timeleft : " << timeLeft << std::endl;
  if (timeLeft <= 0)
    {
      if (unitProd.size() > 0)
        {
	  Pos tempPos = getPos();
	  tempPos.x += 1;
	  //std::cout << "unit at x " << tempPos.x << " y " << tempPos.y << std::endl;
	  newUnit.reset(new Unit(unitProd[0],imgs[unitProd[0].img], tempPos, rand(), alegence, weaponsConf, shotConf));
	  std::vector<ConfUnit> tempVect = unitProd;
	  unitProd.clear();
	  for (int i = 0; i < (int)tempVect.size() - 1; i += 1)
	    unitProd.push_back(tempVect[i + 1]);
	  if (unitProd.size() > 0)
	    timeLeft = unitProd[0].timeToProduce;
	  needToUpdate = true;
        }
    }
  else
    newUnit = nullptr;
  return newUnit;
}
