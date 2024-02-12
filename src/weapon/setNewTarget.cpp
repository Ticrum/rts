// EFRITS
// project:     rts
// created on:  2024-02-09 - 11:40 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: setNewTarget implementation

#include "weapon.hh"

void ef::Weapon::setNewTarget(std::shared_ptr<Object> newTarget)
{
    target = newTarget;
}

