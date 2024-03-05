#include "weapon.hh"

ef::ConfWeapon::ConfWeapon(ConfWeapon const &other)
{
    conf = other.conf;
    dmg = other.dmg;
    nbrAtt = other.nbrAtt;
    range = other.range;
    manualTarget = other.manualTarget;
}
