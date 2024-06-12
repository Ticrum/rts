// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 30/05/2024 15:38:20 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "ia.hh"

#include <iostream>

void ef::Brain::targetInVision(std::string target,
			       Dist dist,
			       double priority,
			       double pressure,
			       bool isPlayer,
			       bool isEnemy)
{
  if (isEnemy)
    {
      for (int i = 0; i < (int)tasks.size(); i += 1)
	{
	  if (target == tasks[i].target)
	    {
	      tasks[i].visType = DIRECT;
	      tasks[i].pressure[0] = pressure;
	      return;
	    }
	}
      std::cout << "targetInVision brain add target in vision" << std::endl;
      tasks.emplace_back(DIRECT, target, dist, priority, pressure, isPlayer, isEnemy);
      return;
    }
  else
    {
      for (int i = 0; i < (int)allyTasks.size(); i += 1)
	{
	  if (target == allyTasks[i].target)
	    {
	      allyTasks[i].visType = DIRECT;
	      allyTasks[i].pressure[0] = pressure;
	      return;
	    }
	}
      allyTasks.emplace_back(DIRECT, target, dist, priority, pressure, isPlayer, isEnemy);
      return;
    }
}

