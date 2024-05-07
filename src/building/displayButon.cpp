// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 26/04/2024 13:12:52 ******************************************************
// romain.piccoche <romain.picoche@laika.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "building.hh"
#include "apiButton.hh"

#include <iostream>

void ef::Building::displayButon(ef::Pos size,
				ef::ButonManager &manager,
				std::function<void(std::string)> func,
				std::map<std::string, std::shared_ptr<ef::Bpixelarray>> &sprits)
{
  t_bunny_accurate_area square;
  square.w = (((double)size.x * 2.0) / 10.0) /3.0;
  square.h = square.w;
  square.x = (square.w / 3.0) + (((double)size.x * 8.0)/ 10.0);
  square.y = square.h / 3.0;
  unsigned int tmp = 0;
  std::string tempon;
  unsigned int max = std::stoul(extract(tmp, butons, ','));
  bool multiPage = false;
  groupButon = manager.nextGroupId();
  bool Case = (extract(tmp, butons, ',')[0] == 'T') ? true : false;
  bool print = true;
  unsigned int outside;
  unsigned int background;
  std::string pxName;
  std::string action;
  std::shared_ptr<ef::Bpixelarray> tmpSprits(new Bpixelarray());
while(tmp < butons.size()&& max > 0)
    {
      outside = std::stoul(extract(tmp, butons, ','));
      background = std::stoul(extract(tmp, butons, ','));
      pxName = extract(tmp, butons, ',');
      action = extract(tmp, butons, ',');
      manager.add(groupButon, print, square, outside, background, ((sprits.count(pxName) == 0)?tmpSprits : sprits[pxName]), action, func, Case);
      if(square.x >= size.x - square.w - ((square.w * 2) / 3.0))
	{
	  square.x = (square.w / 3.0)  + (((double)size.x * 8.0)/ 10.0);
	  square.y += square.h + (square.h / 3.0);
	}
      else
	square.x += square.w + (square.w / 3.0);
      max --;
    }
}
