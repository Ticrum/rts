// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 30/05/2024 16:53:15 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "ia.hh"

void ef::Brain::updateDist(std::string target,
			   Dist newDist,
			   bool isEnemy)
{
  if (isEnemy)
    for (int i = 0; i < (int)tasks.size(); i += 1)
      {
	if (target == tasks[i].target)
	  {
	    tasks[i].dist = newDist;
	    return;
	  }
      }
  else
    for (int i = 0; i < (int)allyTasks.size(); i += 1)
      {
	if (target == allyTasks[i].target)
	  {
	    allyTasks[i].dist = newDist;
	    return;
	  }
      }
}

