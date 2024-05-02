// EFRITS
// project:     rts
// created on:  2024-02-13 - 15:42 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: makeTargeting implementation

#include "building.hh"
#include "unit.hh"

ef::TargetReturn ef::Building::makeTargeting(std::vector<std::shared_ptr<Object>> others,
					     bool isBuilding)
{
    int minDist;
    int actualDist;
    std::shared_ptr<Object> bestTarget;
    TargetReturn tar;

    tar.isBuilding = true;
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
		if (tempObj->getId() != others[j]->getId())
		  occur += 1;
	      if (occur == (int)others.size() && (int)others.size() != 0)
		weapons[i].removeTarget();
	    }
	  objPos = tempObj->getPos();
	  if (!weapons[i].getIsTargetBuild())
	    objPos = static_pointer_cast<Unit>(tempObj)->getActualPos();
	}
      if (!weapons[i].hasTarget() || (weapons[i].hasTarget() && getPos().isInRange(objPos, weapons[i].getRange(), weapons[i].getRange()) == -1))
	{
	  minDist = 999999;
	  for (int j = 0; j < (int)others.size(); j += 1)
	    {
	      if (isBuilding)
		{
		  std::shared_ptr<Building> tempBuilding = static_pointer_cast<Building>(others[j]);
		  if ((actualDist = getPos().isInRange(tempBuilding->getPos(), weapons[i].getRange(), weapons[i].getRange())) != -1 && getAlegence() != others[j]->getAlegence())
		    if (actualDist < minDist && actualDist != -1)
		      {
			minDist = actualDist;
			bestTarget = others[j];
		      }
		}
	      else
		{
		  std::shared_ptr<Unit> tempUnit = static_pointer_cast<Unit>(others[j]);
		  if ((actualDist = getPos().isInRange(tempUnit->getActualPos(), weapons[i].getRange(), weapons[i].getRange())) != -1 && getAlegence() != others[j]->getAlegence())
		    if (actualDist < minDist && actualDist != -1)
		      {
			minDist = actualDist;
			bestTarget = others[j];
		      }
		}
	    }
	  weapons[i].setNewTarget(bestTarget, isBuilding);
	  tar.target.push_back(bestTarget);
	}
    }
    return tar;
}


