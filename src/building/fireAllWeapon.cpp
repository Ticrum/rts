// EFRITS
// project:     rts
// created on:  2024-02-12 - 11:40 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: fireAllWeapon implementation

#include "building.hh"

bool ef::Building::fireAllWeapon(double timePassed)
{
    bool hasFire = false;

    for (int i = 0; i < (int)weapons.size(); i += 1)
        if (weapons[i].fireAction(timePassed))
            hasFire = true;
    return hasFire;
}
