// EFRITS
// project:     rts
// created on:  2024-02-09 - 10:51 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: takeDmg implementation

#include "object.hh"

void ef::Object::takeDmg(int _nbrDmg,
                         int _dmg)
{
    _dmg -= armor;
    if (_dmg <= 0)
        return;
    for (int i = 0; i < _nbrDmg; i += 1)
        hp -= _dmg;
    if (hp < 0)
        hp = 0;
}

