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

void ef::Building::displayButon(ef::ButonManager &manager,
				std::function<void(std::string)> func,
				std::map<std::string, std::shared_ptr<ef::Bpixelarray>> &sprits)
{
  std::cout << "displayButon pass" << std::endl;
  unsigned int tmp = 0;
  std::string tempon;
  unsigned int max = std::stoul(extract(tmp, butons, ','));
  groupButon = manager.nextGroupId();
  bool Case = (extract(tmp, butons, ',')[0] == 'T') ? true : false;
  bool print;
  t_bunny_accurate_area square;
  unsigned int outside;
  unsigned int background;
  std::string pxName;
  std::string action;
  while(tmp < butons.size()&& max > 0)
    {
      print = (extract(tmp,butons, ',')[0] == 'T') ? true : false;
      square.x = std::stod(extract(tmp, butons, ','));
      square.y = std::stod(extract(tmp, butons, ','));
      square.w = std::stod(extract(tmp, butons, ','));
      square.h = std::stod(extract(tmp, butons, ','));
      outside = std::stoul(extract(tmp, butons, ','));
      background = std::stoul(extract(tmp, butons, ','));
      pxName = extract(tmp, butons, ',');
      action = extract(tmp, butons, ',');
      manager.add(groupButon, print, square, outside, background, sprits[pxName], action, func, Case);
      max --;
    }
}
