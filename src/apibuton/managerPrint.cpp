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

void ef::ButonManager::print(std::shared_ptr<ef::Bpixelarray> px,
			     Pos start,
			     double ratioCasePix)
{
  Pos min;
  AcuPos max;
  for(unsigned int i = 0; i < groupIds.size(); ++i)
    {
      unsigned int chariot = 0;
      while(chariot < group[groupIds[i]].buton.size())
	{
	  min.x = (group[groupIds[i]].buton[chariot].square.x - start.x) * ratioCasePix;
	  min.y = (group[groupIds[i]].buton[chariot].square.y - start.y) * ratioCasePix;
	  max.x = group[groupIds[i]].buton[chariot].square.w * ratioCasePix;
	  max.y = group[groupIds[i]].buton[chariot].square.h * ratioCasePix;
	  if(group[groupIds[i]].buton[chariot].sprit->GetClip() != NULL)
	    px->Blit(*group[groupIds[i]].buton[chariot].sprit, min, max);
	  else
	    px->rectangle(min, max, group[groupIds[i]].buton[chariot].background.full, group[groupIds[i]].buton[chariot].outside.full);
	  chariot ++;
	}
    }
}

