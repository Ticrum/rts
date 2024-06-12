// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 28/05/2024 16:35:38 ******************************************************
// romain.piccoche <romain.picoche@laika.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "object.hh"
#include "apiButton.hh"
#include <iostream>
static void nothing (std::string msg)
{
  static_cast<void>(msg);
}

void ef::Object::displayInfo(ef::Pos &start,
			     ef::Pos &size,
			     ef::ButonManager &manager,
			     std::map<std::string, std::shared_ptr<Bpixelarray>> &sprits)
{
  std::string font("font.png");
  ef::AcuPos sizeFont ;
  sizeFont.x = sprits[font]->GetSize().x/ 127.0;
  sizeFont.y = sprits[font]->GetSize().y;
  size.x = 0.7 * size.x;
  size.y = 0.3 * size.y;
  t_bunny_accurate_area square;
  square.x = start.x;
  square.y = start.y;
  square.w = size.x;
  square.h = size.y;
  //std::cout << "là" << std::endl;
  //std::cout<< "__--DI--__\ntx: "<< start.x << "\nty: "<< start.y << "\nsx: "<< size.x << "\nsy: "<< size.y << "\nx " << square.x << "\ny " << square.y<< "\nh " << square.h << "\nw " << square.w << std::endl;
  //manager.add(groupButon, true, square, GREEN, GREEN, std::make_shared<ef::Bpixelarray>(), "yes", nothing, false);
  square.x = start.x + 1.0/15.0 * size.y;
  square.w = 1.0/2.0 * size.y;
  square.y = start.y + size.y/2.0 - square.w /2;
  square.h = square.w;
  manager.add(groupButon, true, square, BLUE, BLUE, img, "yes", nothing, false);
  ef::Pos tempon;
  tempon.x = start.x + (size.x / 2.0) - ((conf.size() * sizeFont.x) / 2.0);
  tempon.y = start.y + (2.0/15.0 * size.y)/2 - sizeFont.y / 2.0;
  labbelId.push_back(manager.add(tempon, sizeFont,conf,sprits[font]));

  tempon.x = start.x + size.x - sizeFont.x * (std::to_string(armor).size() + 8);
  tempon.y += sizeFont.y;
  labbelId.push_back(manager.add(tempon, sizeFont,"armor: " + std::to_string(armor),sprits[font]));

  tempon.x = start.x + size.x - sizeFont.x * (std::to_string(dmg).size() + 15 + std::to_string(nbrDmg).size());
  tempon.y += sizeFont.y * 3 / 2;
  labbelId.push_back(manager.add(tempon, sizeFont,"explotion: " + std::to_string(dmg) + "(x" + std::to_string(nbrDmg) + ")",sprits[font]));
  tempon.x = square.x + square.w/2.0 - sizeFont.x * ((double)(std::to_string(hp).size() + 3 + std::to_string(maxhp).size())/2.0) ;
  tempon.y = start.y + (square.y - start.y)/2 - sizeFont.y / 2.0;
  labbelId.insert(labbelId.begin(), manager.add(tempon, sizeFont, std::to_string(hp) + " / " + std::to_string(maxhp),sprits[font]));
}
