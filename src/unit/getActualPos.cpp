// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 18/03/2024 17:04:37 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "unit.hh"

ef::Pos ef::Unit::getActualPos()
{
  if ((int)path.size() == 0 || actualIndex == 0)
    return getPos();
  return path[actualIndex - 1];
}

ef::Pos ef::Unit::getActualPos(int decal)
{
  if ((int)path.size() == 0 || actualIndex == 0 || actualIndex - 1 + decal < 0)
    return getPos();
  return path[actualIndex - 1 + decal];
}

