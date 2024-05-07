// EFRITS
// project:     rts
// created on:  2024-02-09 - 13:04 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: weapon implementation

#include "weapon.hh"

ef::Weapon::Weapon(ConfWeapon conf,
		   int _alegence,
		   ConfObj _shot)
    :
    dmg(conf.dmg),
    nbrAtt(conf.nbrAtt),
    cdrMax(conf.cdrMax),
    cdr(cdrMax),
    range(conf.range),
    manualTarget(conf.manualTarget),
    alegence(_alegence),
    shot(_shot),
    target(nullptr)
{
}

