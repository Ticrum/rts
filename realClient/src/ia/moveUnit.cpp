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

#include <iostream>

void ef::Ia::moveUnit(double timePassed)
{
  if (unitToProd == 0)
    {
      std::vector<std::shared_ptr<Unit>> & tempOtherUnit = cli.playerInfo.getOtherUnits();
      std::vector<std::shared_ptr<Unit>> & myUnit = cli.playerInfo.getUnits();
      double myPressure = 0;
      for (int i = 0; i < (int)myUnit.size(); i += 1)
	myPressure += 1;
      //std::cout << "moveUnit ia tempOtherUnit size : " << tempOtherUnit.size() << std::endl;
      //std::cout << "moveUnit ia pressure size : " << pressure.size() << std::endl;
      //std::cout << "moveUnit ia alegences size : " << alegences.size() << std::endl;
      for (int i = 0; i < (int)pressure.size(); i += 1)
	pressure[i] = 0;
      for (int i = 0; i < (int)tempOtherUnit.size(); i += 1)
	{
	  bool asFound = false;
	  for (int j = 0; j < (int)alegences.size(); j += 1)
	    if (tempOtherUnit[i]->getAlegence() == alegences[j])
	      {
		pressure[j] += 1;
		asFound = true;
		break;
	      }
	  if (!asFound)
	    {
	      std::cout << "moveUnit ia as found unit" << std::endl;
	      alegences.push_back(tempOtherUnit[i]->getAlegence());
	      pressure.push_back(1);
	    }
	}
      for (int i = 0; i < (int)pressure.size(); i += 1)
	{
	  if (pressure[i] == 0)
	    {
	      brain.targetOutVision(std::to_string(alegences[i]), true);
	      int tempAlegences = alegences[alegences.size() - 1];
	      alegences[alegences.size() - 1] = alegences[i];
	      alegences[i] = tempAlegences;
	      alegences.pop_back();
	      double tempPressure = pressure[pressure.size() - 1];
	      pressure[pressure.size() - 1] = pressure[i];
	      pressure[i] = tempPressure;
	      pressure.pop_back();
	    }
	  else
	    {
	      std::cout << "moveUnit ia pass in add target" << std::endl;
	      brain.targetInVision(std::to_string(alegences[i]), MID, 1, (pressure[i] / myPressure) * 4, true, true);
	    }
	}
      std::vector<Action> tempAction = brain.getActions(timePassed);
      //std::cout << "manageUnitProduction ia tempAction size : " << tempAction.size() << std::endl;

      Pos pos[2];
      pos[0].x = 0;
      pos[0].y = 0;
      pos[1].x = mapSize.x;
      pos[1].y = mapSize.y;

      cli.select(size, pos[0], pos[1], singleCommand, false);
      std::vector<std::shared_ptr<Building>> & tempBuilding = cli.playerInfo.getOtherBuild();
      pos[0].x = mapSize.x / 2;
      pos[0].y = mapSize.y / 2;
      /*
      if (tempUnit.size() > 0)
	pos[0] = tempUnit[0]->getActualPos();
      else if (tempBuilding.size() > 0)
	pos[0] = tempBuilding[0]->getPos();
      */
      if (tempAction.size() > 0)
	for (int i = 0; i < (int)tempOtherUnit.size(); i += 1)
	  if (tempOtherUnit[i]->getAlegence() == tempAction[0].target[0] - '0')
	    {
	      if (tempAction[0].actType == RETREAT || tempAction[0].actType == FLEE || tempAction[0].actType == ALLOUT_FLEE)
		pos[0] = MainBuild[0]->getPos();
	      else
		pos[0] = tempOtherUnit[i]->getActualPos();
	      break;
	    }
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

