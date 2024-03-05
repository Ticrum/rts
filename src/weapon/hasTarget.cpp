// EFRITS
// project:     rts
// created on:  2024-02-23 - 17:00 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: hasTarget implementation

#include "weapon.hh"

bool ef::Weapon::hasTarget()
{
    return target.get() != nullptr;
}

