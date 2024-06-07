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

void ef::Brain::targetFastCheck(std::string target,
				Dist dist,
				double priority,
				double pressure,
				bool isPlayer,
				bool isEnemy)
{
  if (isEnemy)
    for (int i = 0; i < (int)tasks.size(); i += 1)
      {
	if (target == tasks[i].target)
	  {
	    tasks[i].visType = INDIRECT;
	    tasks[i].pressure[0] = pressure;
	    return;
	  }
	else
	  {
	    tasks.emplace_back(INDIRECT, target, dist, priority, pressure, isPlayer, isEnemy);
	    return;
	  }
      }
  else
    for (int i = 0; i < (int)allyTasks.size(); i += 1)
      {
	if (target == allyTasks[i].target)
	  {
	    allyTasks[i].visType = INDIRECT;
	    allyTasks[i].pressure[0] = pressure;
	    return;
	  }
	else
	  {
	    allyTasks.emplace_back(INDIRECT, target, dist, priority, pressure, isPlayer, isEnemy);
	    return;
	  }
      }
}
