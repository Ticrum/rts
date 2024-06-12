// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 24/05/2024 11:15:37 ******************************************************
// romain.piccoche <romain.picoche@laika.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "apiButton.hh"

void ef::ButonManager::popLabbel(unsigned int id)
{
  if(groupLab.count(id) == 0)
    return;
  for(unsigned int i = 0; i < groupLabIds.size(); ++i)
    if(groupLabIds[i] == id)
      {
	groupLab.erase(groupLabIds[i]);
	groupLabIds.erase(groupLabIds.begin() + i);
      }
}
