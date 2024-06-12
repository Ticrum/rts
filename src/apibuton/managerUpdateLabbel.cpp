// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 05/06/2024 15:00:40 ******************************************************
// romain.piccoche <romain.picoche@gagarine.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "apiButton.hh"

void ef::ButonManager::updateLabbel(unsigned int id,
				    std::string msg,
				    ef::Pos pos,
				    std::shared_ptr<ef::Bpixelarray> font,
				    ef::AcuPos size)
{
  
  for (unsigned int i = 0; i < groupLabIds.size(); ++i)
    {
      if(groupLabIds[i] == id)
	{
	  if(groupLab[groupLabIds[i]].text != msg)
	    groupLab[groupLabIds[i]].text = msg;
	  if(font->GetClip() != NULL)
	    groupLab[groupLabIds[i]].font = font;
	  if(pos.x >= 0)
	    {
	      groupLab[groupLabIds[i]].square.x = pos.x;
	      groupLab[groupLabIds[i]].square.y = pos.y;
	    }
	  if(size.x >= 0.0)
	    groupLab[groupLabIds[i]].usableSize(size);
	  return;
	}
    }
}
