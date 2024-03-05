#include "weapon.hh"

ef::ConfWeapon &ef::ConfWeapon::operator=(ConfWeapon const&other)
{
    conf= other.conf;
    dmg= other.dmg;
    nbrAtt= other.nbrAtt;
    cdrMax= other.cdrMax;
    range = other.range;
    manualTarget = other.manualTarget;
    return *this;
}
