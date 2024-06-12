// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 31/05/2024 12:53:15 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "ia.hh"

void ef::Brain::avoidImediateDanger(std::vector<Action> & actions)
{
  double totalPressure = 0;
  Action tempAct;

  for (int i = 0; i < (int)tasks.size(); i += 1)
    if (tasks[i].isPlayer)
      totalPressure += tasks[i].pressure[0];
  for (int i = 0; i < (int)allyTasks.size(); i += 1)
    if (allyTasks[i].isPlayer && allyTasks[i].pressure[0] < 0)
      totalPressure += allyTasks[i].pressure[0];
  totalPressure = totalPressure / agressive;
  if (totalPressure < 9 && totalPressure > 8)
    tempAct.actType = RETREAT;
  else if (totalPressure < 11 && totalPressure > 8)
    tempAct.actType = FLEE;
  else if (totalPressure > 8)
    tempAct.actType = ALLOUT_FLEE;
  for (int i = 0; i < (int)tasks.size(); i += 1)
    if (tasks[i].isPlayer)
      {
	tempAct.target = tasks[i].target;
	actions.push_back(tempAct);
      }
}


