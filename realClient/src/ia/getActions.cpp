// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 30/05/2024 17:11:07 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "ia.hh"

#include <iostream>

std::vector<ef::Action> ef::Brain::getActions(double timePassed)
{
  std::vector<Action> actions;
  Action bestActObjective;
  Action bestActPlayer;
  double bestPrio = 0;
  int bestIndex = -1;

  //std::cout << "getActions brain tasks size : " << tasks.size() << std::endl;
  updatePressureTime(timePassed);
  for (int i = 0; i < (int)tasks.size(); i += 1)
    if (!tasks[i].isPlayer && tasks[i].priority * protecting > bestPrio)
      {
	bestPrio = tasks[i].priority * protecting;
	bestActObjective.target = tasks[i].target;
	bestIndex = i;
      }
  if (bestIndex != -1)
    {
      double pressureResult = tasks[bestIndex].pressure[0] / agressive;
      if (pressureResult < 3)
	bestActObjective.actType = PROTECT;
      else if (pressureResult < 6)
	bestActObjective.actType = PROTECT_FROM_DIST;
      else if (pressureResult < 8)
	bestActObjective.actType = RETREAT;
      else if (pressureResult < 9)
	bestActObjective.actType = FLEE;
      else
	bestActObjective.actType = ALLOUT_FLEE;
      actions.push_back(bestActObjective);
    }

  avoidImediateDanger(actions);

  bestIndex = -1;
  for (int i = 0; i < (int)tasks.size(); i += 1)
    if (tasks[i].isPlayer && tasks[i].priority > bestPrio)
      {
	std::cout << "getActions brain new prio" << std::endl;
	bestPrio = tasks[i].priority;
	bestActPlayer.target = tasks[i].target;
	bestIndex = i;
      }
  if (bestIndex != -1)
    {
      std::cout << "getActions brain set action" << std::endl;
      double pressureResult = tasks[bestIndex].pressure[0] / agressive;
      if (pressureResult < 3)
	bestActPlayer.actType = ATTACK;
      else if (pressureResult < 6)
	bestActPlayer.actType = POKE;
      else if (pressureResult < 8)
	bestActPlayer.actType = RETREAT;
      else if (pressureResult < 9)
	bestActPlayer.actType = FLEE;
      else
	bestActPlayer.actType = ALLOUT_FLEE;
      actions.push_back(bestActPlayer);
    }

  bestIndex = -1;
  for (int i = 0; i < (int)allyTasks.size(); i += 1)
    if (allyTasks[i].isPlayer && allyTasks[i].priority > bestPrio)
      {
	bestPrio = allyTasks[i].priority;
	bestActPlayer.target = allyTasks[i].target;
	bestIndex = i;
      }
  if (bestIndex != -1)
    {
      double pressureResult = allyTasks[bestIndex].pressure[0];
      if (pressureResult < 3)
	bestActPlayer.actType = PROTECT_FROM_DIST;
      else if (pressureResult / protecting < 6 && pressureResult > 0)
	bestActPlayer.actType = PROTECT;
      else if (pressureResult / protecting < 8 && pressureResult > 0)
	bestActPlayer.actType = PROTECT_AT_ALL_COST;
      else if (pressureResult / protecting < 9 && pressureResult > 0)
	bestActPlayer.actType = RETREAT;
      else
	bestActPlayer.actType = FLEE;
      actions.push_back(bestActPlayer);
    }
  return actions;
}

