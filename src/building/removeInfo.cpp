// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 28/04/2024 16:39:45 ******************************************************
// romain.piccoche <romain.picoche@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "building.hh"
#include "apiButton.hh"

void ef::Building::removeInfo(ef::ButonManager &manager)
{
  for(unsigned int i = 0; i < labbelId.size(); ++i)
    manager.popLabbel(labbelId[i]);
  labbelId.clear();
  manager.pop(groupButon);
}
