// EFRITS
// project:     rts
// created on:  2024-02-09 - 10:51 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: takeDmg implementation

#include "object.hh"

#include <iostream>

void ef::Object::takeDmg(int _nbrDmg,
                         int _dmg)
{
  std::cout << "takeDmg hp beafore : " << hp << " dmg : " << _dmg << " nbrdmg : " << _nbrDmg << std::endl;
  _dmg -= armor;
  if (_dmg <= 0)
    return;
  for (int i = 0; i < _nbrDmg; i += 1)
    hp -= _dmg;
  if (hp < 0)
    hp = 0;
  std::cout << "takeDmg hp after : " << hp << std::endl;
}

