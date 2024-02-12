// EFRITS
// project:     rts
// created on:  2024-02-09 - 11:27 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: fireAction implementation

#include "weapon.hh"

bool ef::Weapon::fireAction(double timePassed)
{
    cdr -= timePassed;
    if (cdr < 0)
        cdr = 0;
    if (target.get() != nullptr && cdr == 0)
    {
        target->takeDmg(nbrAtt, dmg);
        cdr = cdrMax;
        return true;
    }
    return false;
}

