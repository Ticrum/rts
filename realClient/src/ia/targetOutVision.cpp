// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 30/05/2024 16:14:30 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "ia.hh"

#include <iostream>

void ef::Brain::targetOutVision(std::string target,
				bool isEnemy)
{
  if (isEnemy)
    {
      for (int i = 0; i < (int)tasks.size(); i += 1)
	if (tasks[i].target == target)
	  {
	    std::cout << "targetOutVision brain removeTarget from vision" << std::endl;
	    tasks[i].visType = INDIRECT;
	    return;
	  }
    }
  else
    {
      for (int i = 0; i < (int)tasks.size(); i += 1)
	if (allyTasks[i].target == target)
	  {
	    allyTasks[i].visType = INDIRECT;
	    return;
	  }
    }
}

