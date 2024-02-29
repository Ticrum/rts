// EFRITS
// project:     rts
// created on:  2024-02-29 - 12:36 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: weapon2 implementation

#include "weapon.hh"

ef::Weapon::Weapon(ConfWeapon conf,
                   double _cdr)
    :
    dmg(conf.dmg),
    nbrAtt(conf.nbrAtt),
    cdrMax(conf.cdrMax),
    cdr(_cdr),
    range(conf.range),
    manualTarget(conf.manualTarget),
    target(nullptr)
{
}

