// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 22/05/2024 13:22:37 ******************************************************
// romain.piccoche <romain.picoche@gagarine.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "building.hh"
#include "apiButton.hh"
#include <iostream>

void ef::Building::displayInfo(ef::Pos size,
			       ButonManager &manager,
			       std::map<std::string, std::shared_ptr<Bpixelarray>> &sprits)
{
  std::string font("font.png");
  ef::Pos start;
  start.x = 0.3 * size.x;
  start.y = 0.7 * size.y;
  int dmg = 0;
  for(unsigned int i = 0; i < weapons.size(); i++)
    dmg += weapons[i].getDmg() * weapons[i].getNbrAtt();
  ef::Object::displayInfo(start, size, manager,sprits);
  ef::AcuPos sizeFont ;
  sizeFont.x = sprits[font]->GetSize().x/ 127.0;
  sizeFont.y = sprits[font]->GetSize().y;
  ef::Pos tempon;
  tempon.x = start.x + size.x - sizeFont.x * (std::to_string(dmg).size() + 11);
  tempon.y = start.y + (2.0/15.0 * size.y)/2 + sizeFont.y * 7.0 / 2.0;
  labbelId.insert(labbelId.end(), manager.add(tempon, sizeFont,"by atck.: " +std::to_string(dmg),sprits[font]));
      /*
	labbelId.push_back(manager.add(,,"energy cost: " + std::to_string(energyCost),));
    labbelId.push_back(manager.add(,,"energy production: " + std::to_string(energyProduction),));
    labbelId.push_back(manager.add(,,"money production: " + std::to_string(moneyProduction),));
      */
  for(unsigned int i = 0; i < labbelId.size(); i++)
    std::cout << labbelId[i]<< std::endl;
}
