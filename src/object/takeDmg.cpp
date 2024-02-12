// EFRITS
// project:     rts
// created on:  2024-02-09 - 10:51 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: takeDmg implementation

#include "object.hh"

void ef::Object::takeDmg(int nbrDmg,
                         int dmg)
{
    dmg -= armor;
    if (dmg <= 0)
        return;
    for (int i = 0; i < nbrDmg; i += 1)
        hp -= dmg;
    if (hp < 0)
        hp = 0;
}

