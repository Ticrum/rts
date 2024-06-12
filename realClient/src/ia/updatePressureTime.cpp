// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 31/05/2024 16:23:22 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "ia.hh"

void ef::Brain::updatePressureTime(double timePassed)
{
  int nbrloop = (int)(timePassed / (1.0 / 60.0));
  for (int j = 0; j < nbrloop; j += 1)
    {
      for (int i = 0; i < (int)tasks.size(); i += 1)
	decalPresure(tasks[i]);
      for (int i = 0; i < (int)allyTasks.size(); i += 1)
	decalPresure(allyTasks[i]);
    }
}


