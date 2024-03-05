// EFRITS
// project:     rts
// created on:  2024-02-22 - 15:53 +0100
// 1st author:  romain.piccoche - romain.picoche
// description: download weapon configuration

#include "weapon.hh"

ef::ConfWeapon::ConfWeapon(std::string file)
    :dmg(-1)
{
    for (unsigned int i = 0; i < 10 && load(file); i++);
}
