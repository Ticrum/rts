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

void ef::Brain::updatePriority(std::string target,
			       double newPrio,
			       bool isEnemy)
{
  if (isEnemy)
    for (int i = 0; i < (int)tasks.size(); i += 1)
      {
	if (target == tasks[i].target)
	  {
	    tasks[i].priority = newPrio;
	    return;
	  }
      }
  else
    for (int i = 0; i < (int)allyTasks.size(); i += 1)
      {
	if (target == allyTasks[i].target)
	  {
	    allyTasks[i].priority = newPrio;
	    return;
	  }
      }
}

