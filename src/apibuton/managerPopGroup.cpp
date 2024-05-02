// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 26/04/2024 10:59:29 ******************************************************
// romain.piccoche <romain.picoche@laika.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "apiButton.hh"

void ef::ButonManager::pop(unsigned int groupp)
{
  if(group.count(groupp) != 0)
    {
      group.erase(groupp);
      for(unsigned int i = 0; i < groupIds.size(); i++)
	if(groupp == groupIds[i])
	  {
	    unsigned int gpId = groupIds[i];
	    groupIds[i] = groupIds[groupIds.size()];
	    groupIds[groupIds.size()] = gpId;
	    groupIds.pop_back();
	  }
    }
}
