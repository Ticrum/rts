// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 24/04/2024 12:37:06 ******************************************************
// romain.piccoche <romain.picoche@laika.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "apiButton.hh"

int ef::ButonManager::hide(unsigned int groupp,
			   unsigned int id)
{
  if(group.count(groupp) != 0)
    {
      for(unsigned int i = 0; i < group[groupp].buton.size(); i ++)
        if(group[groupp].buton[i].id == id)
	  {
	    group[groupp].buton[i].print = false;
	    return 0;
	  }
      return 2;
    }
  return 1;
}
