// EFRITS
// project:     rts
// created on:  2024-02-12 - 18:03 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: makeTargeting implementation

#include "unit.hh"
#include "building.hh"

#include <iostream>

ef::TargetReturn ef::Unit::makeTargeting(std::vector<std::shared_ptr<Object>> others,
					 bool isBuilding)
{
  int minDist;
  int actualDist;
  std::shared_ptr<Object> bestTarget = nullptr;
  TargetReturn tar;

  tar.isBuilding = false;
  for (int i = 0; i < (int)weapons.size(); i += 1)
    {
      std::shared_ptr<Object> tempObj;
      Pos objPos;
      if (weapons[i].hasTarget())
	{
	  tempObj = weapons[i].getTarget();
	  if (isBuilding == weapons[i].getIsTargetBuild())
	    {
	      int occur = 0;
	      for (int j = 0; j < (int)others.size(); j += 1)
		{
		  //std::cout << "makeTargeting other ID : " << others[j]->getId() << "target ID : " << tempObj->getId() << std::endl;
		  if (tempObj->getId() != others[j]->getId())
		    occur += 1;
		}
	      if (occur == (int)others.size() && (int)others.size() != 0)
		{
		  //std::cout << "makeTargeting supptarget" << std::endl;
		  weapons[i].removeTarget();
		}
	    }
	  objPos = tempObj->getPos();
	  if (!weapons[i].getIsTargetBuild())
	    {
	      objPos = static_pointer_cast<Unit>(tempObj)->getActualPos();
	      //std::cout << "makeTargeting is unit" << std::endl;
	    }
	  //std::cout << "makeTargeting objpos x : " << objPos.x << " y : " << objPos.y << std::endl;
	}
      if (!weapons[i].hasTarget() || (weapons[i].hasTarget() && getActualPos().isInRange(objPos, weapons[i].getRange(), weapons[i].getRange()) == -1))
        {
	  //std::cout << "makeTargeting check for new target size : " << others.size() << std::endl;
	  minDist = 999999;
	  for (int j = 0; j < (int)others.size(); j += 1)
	    {
	      if (isBuilding)
		{
		  std::shared_ptr<Building> tempBuilding = static_pointer_cast<Building>(others[j]);
		  //std::cout << "makeTargeting other pos x : " << tempBuilding->getPos().x << " y : " << tempBuilding->getPos().y << std::endl;
		  //std::cout << "makeTargeting pos x : " << getActualPos().x << " y : " << getActualPos().y << std::endl;
		  if ((actualDist = getActualPos().isInRange(tempBuilding->getPos(), weapons[i].getRange(), weapons[i].getRange())) != -1 && getAlegence() != others[j]->getAlegence())
		    if (actualDist < minDist && actualDist != -1)
		      {
			//std::cout << "makeTargeting find new min" << std::endl;
			minDist = actualDist;
			bestTarget = others[j];
		      }
		}
	      else
		{
		  std::shared_ptr<Unit> tempUnit = static_pointer_cast<Unit>(others[j]);
		  //std::cout << "makeTargeting other pos x : " << tempUnit->getActualPos().x << " y : " << tempUnit->getActualPos().y << std::endl;
		  //std::cout << "makeTargeting pos x : " << getActualPos().x << " y : " << getActualPos().y << std::endl;
		  if ((actualDist = getActualPos().isInRange(tempUnit->getActualPos(), weapons[i].getRange(), weapons[i].getRange())) != -1 && getAlegence() != others[j]->getAlegence())
		    if (actualDist < minDist && actualDist != -1)
		      {
			//std::cout << "makeTargeting find new min" << std::endl;
			minDist = actualDist;
			bestTarget = others[j];
		      }
		}
	    }
	  //if (bestTarget.get() != nullptr)
	  //  std::cout << "makeTargeting besttarget ID : " << bestTarget->getId() << std::endl;
	  weapons[i].setNewTarget(bestTarget, isBuilding);
	  tar.target.push_back(bestTarget);
        }
    }
  return tar;
}

