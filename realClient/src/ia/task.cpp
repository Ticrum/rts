// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 30/05/2024 16:03:02 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "ia.hh"

ef::Task::Task(TypeVision _visType,
	       std::string _target,
	       Dist _dist,
	       double _priority,
	       double _pressure,
	       bool _isPlayer,
	       bool _isEnemy)
  :
  visType(_visType),
  target(_target),
  dist(_dist),
  priority(_priority),
  isPlayer(_isPlayer),
  isEnemy(_isEnemy)
{
  for(int i = 0; i < 60; i += 1)
    pressure[i] = 0;
  pressure[0] = _pressure;
}

ef::Task::Task(Task const & other)
  :
  visType(other.visType),
  target(other.target),
  dist(other.dist),
  priority(other.priority),
  isPlayer(other.isPlayer),
  isEnemy(other.isEnemy)
{
  for(int i = 0; i < 60; i += 1)
    pressure[i] = other.pressure[i];
}

ef::Task & ef::Task::operator=(Task const & other)
{
  visType = other.visType;
  target = other.target;
  dist = other.dist;
  priority = other.priority;
  for(int i = 0; i < 60; i += 1)
    pressure[i] = other.pressure[i];
  isPlayer = other.isPlayer;
  isEnemy = other.isEnemy;
  return *this;
}

