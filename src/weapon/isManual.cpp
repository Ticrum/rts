// EFRITS
// project:     rts
// created on:  2024-02-13 - 11:21 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: isManual implementation

#include "weapon.hh"

bool ef::Weapon::isManual()
{
    return manualTarget;
}

