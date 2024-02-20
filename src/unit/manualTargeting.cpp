// EFRITS
// project:     rts
// created on:  2024-02-13 - 11:09 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: manualTargeting implementation

#include "unit.hh"

void ef::Unit::manualTargeting(std::shared_ptr<Object> target)
{
    for (int i = 0; i < (int)weapons.size(); i += 1)
        if (weapons[i].isManual())
            weapons[i].setNewTarget(target);
}

