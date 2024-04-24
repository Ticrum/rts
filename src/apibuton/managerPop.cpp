// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 28/03/2024 12:05:32 ******************************************************
// romain.piccoche <romain.picoche@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "apiButton.hh"

void ef::ButonManager::pop(unsigned int groupp,
			   unsigned int id)
{
  if(group.count(groupp) != 0)
    {
      unsigned int max = group[groupp].buton.size();
      for(unsigned int i = 0; i < max; ++i)
	{
	  if(group[groupp].buton[i].id == id)
	    {
	      ef::Buton tmp = group[groupp].buton[group[groupp].buton.size() - 1];
	      group[groupp].buton[group[groupp].buton.size() - 1] = group[groupp].buton[i];
	      group[groupp].buton[i] = tmp;
	      group[groupp].buton.pop_back();
	      max --;
	      group[groupp].min.x = 1000000000;
	      group[groupp].min.y = 1000000000;
	      group[groupp].max.x = 0;
	      group[groupp].max.y = 0;
	      for(unsigned int i = 0; i < max; ++i)
	        group[groupp].update(group[groupp].buton[i].square);
	      group[groupp].Id = max;
	      return;
	    }
	}
    }
}
