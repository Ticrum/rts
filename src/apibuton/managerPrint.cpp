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
  Pos min;
  AcuPos mina;
  AcuPos max;
  unsigned int chariot;
  for(unsigned int i = 0; i < groupIds.size(); ++i)
    {
      chariot = 0;
      while(chariot < group[groupIds[i]].buton.size())
	{
	  if(group[groupIds[i]].buton[chariot].print)
	    {
	      min.x = (group[groupIds[i]].buton[chariot].square.x - start.x) * ratioCasePix;
	      min.y = (group[groupIds[i]].buton[chariot].square.y - start.y) * ratioCasePix;
	      max.x = group[groupIds[i]].buton[chariot].square.w * ratioCasePix;
	      max.y = group[groupIds[i]].buton[chariot].square.h * ratioCasePix;
	      //std::cout << "group : " << groupIds[i]<< "\nid : " << group[groupIds[i]].buton[chariot].id << "(" << (group[groupIds[i]].buton[chariot].sprit->GetClip()==NULL? "nul": "px!")<< ")"<< std::endl;
	      if(group[groupIds[i]].buton[chariot].sprit->GetClip() != NULL)
		  px.Blit(*group[groupIds[i]].buton[chariot].sprit, min, max);
	      else
		{
		  mina.x = min.x;
		  mina.y = min.y;
		  //std::cout<< "je suis un buton oui\n-start : " << mina.x << " | " << mina.y <<"\n-size : " << max.x << " | " << max.y << std::endl;
		  px.rectangle(mina, max,
			       group[groupIds[i]].buton[chariot].background.full,
			       group[groupIds[i]].buton[chariot].outside.full);
		}
	    }
	  chariot ++;
	}
    }
  if(px.recVec.length > 0)
    {
      //xstd::cout<< "__--" << px.recVec.length << "--__\nx " << px.recVec.vertex[0].pos.x << "\ny " << px.recVec.vertex[0].pos.y<< "\nx " << px.recVec.vertex[1].pos.x << "\ny " << px.recVec.vertex[1].pos.y << "\nx " << px.recVec.vertex[2].pos.x << "\ny " << px.recVec.vertex[2].pos.y << "\nx " << px.recVec.vertex[3].pos.x << "\ny " << px.recVec.vertex[3].pos.y << std::endl;
      bunny_set_geometry(&px.GetClip()->buffer, BGY_QUADS, (t_bunny_vertex_array *)&px.recVec, NULL);
      px.recVec.length = 0;
    }
  for(unsigned int i=0; i < groupLabIds.size(); ++i)
    {
      //std::cout << "text ("<< i<<"): "<<groupLab[groupLabIds[i]].text<< std::endl;
      groupLab[groupLabIds[i]].print(px);
    }
  /*else
    std::cout<< "F" << std::endl;*/
}

