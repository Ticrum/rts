// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 28/03/2024 18:23:00 ******************************************************
// romain.piccoche <romain.picoche@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "apiButton.hh"

#include <iostream>

void ef::ButonManager::print(ef::Bpixelarray &px,
			     Pos start,
			     double ratioCasePix)
{
  std::cout << "print pass" << std::endl;
  Pos min;
  AcuPos max;
  for(unsigned int i = 0; i < groupIds.size(); ++i)
    {
      unsigned int chariot = 0;
      while(chariot < group[groupIds[i]].buton.size())
	{
	  if(group[groupIds[i]].buton[chariot].print)
	    {
	      min.x = (group[groupIds[i]].buton[chariot].square.x - start.x) * ratioCasePix;
	      min.y = (group[groupIds[i]].buton[chariot].square.y - start.y) * ratioCasePix;
	      max.x = group[groupIds[i]].buton[chariot].square.w * ratioCasePix;
	      max.y = group[groupIds[i]].buton[chariot].square.h * ratioCasePix;
	      if(group[groupIds[i]].buton[chariot].sprit->GetClip() != NULL)
		px.Blit(*group[groupIds[i]].buton[chariot].sprit, min, max);
	      else
		px.rectangle(min, max, group[groupIds[i]].buton[chariot].background.full, group[groupIds[i]].buton[chariot].outside.full);
	    }
	  chariot ++;
	}
    }
}

