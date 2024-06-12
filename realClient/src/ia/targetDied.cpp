// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 30/05/2024 16:31:31 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "ia.hh"

void ef::Brain::targetDied(std::string target,
			   bool isEnemy)
{
  if (isEnemy)
    {
      for (int i = 0; i < (int)tasks.size(); i += 1)
	if (tasks[i].target == target)
	  {
	    Task temp(tasks.back());
	    tasks.back() = tasks[i];
	    tasks[i] = temp;
	    tasks.pop_back();
	    return;
	  }
    }
  else
    {
      for (int i = 0; i < (int)tasks.size(); i += 1)
	if (allyTasks[i].target == target)
	  {
	    Task temp(allyTasks.back());
	    allyTasks.back() = allyTasks[i];
	    allyTasks[i] = temp;
	    allyTasks.pop_back();
	    return;
	  }
    }
}

