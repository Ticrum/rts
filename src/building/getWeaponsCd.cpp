// EFRITS
// project:     rts
// created on:  2024-02-23 - 11:05 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: getWeaponsCd implementation

#include "building.hh"

std::vector<double> ef::Building::getWeaponsCd()
{
    std::vector<double> weaponCds;
    for(int i = 0; i < (int)weapons.size(); i += 1)
        weaponCds.push_back(weapons[i].getCdr());
    return weaponCds;
}

