// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 22/04/2024 15:50:40 ******************************************************
// romain.piccoche <romain.picoche@laika.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "apiButton.hh"
#include <iostream>

ef::Pos ef::ButonManager::add(unsigned int groupp,
			      bool print,
			      t_bunny_accurate_area square,
			      unsigned int outside,
			      unsigned int background,
			      std::shared_ptr<ef::Bpixelarray> px,
			      std::string action,
			      std::function<void(std::string)> func,
			      bool Case)
{
  //std::cout<< "__--AD--__\nx " << square.x << "\ny " << square.y<< "\nh " << square.h << "\nw " << square.w << std::endl;
 Pos end(-1);
  if(group.count(groupp) != 0)
    {
      if(Case == group[groupp].Case)
	{
	  //std::cout<< "AD Yes " << Case << std::endl;
	  end.y = group[groupp].update(square);
	  group[groupp].buton.push_back(ef::Buton(groupp, end.y, print, square, outside, background, px, action, func));
	  end.x = groupp;
	}
      /*else
	std::cout<< "AD FUCK ( " << Case << "=="<< group[groupp].Case << std::endl;*/
    }
  else
    {
      //std::cout << "add new one, buton" <<std::endl;
      Groupe tmp;
      group[groupp] = tmp;
      if(Case)
	group[groupp].alowCase();
      end.y = group[groupp].update(square);
      group[groupp].buton.push_back(ef::Buton(groupp, end.y, print, square, outside, background, px, action, func));
      groupIds.push_back(groupp);
      end.x = groupp;
    }
  return end;
}
