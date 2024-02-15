// EFRITS
// project:     rts
// created on:  2024-02-13 - 15:45 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: manualTargeting implementation

#include "building.hh"

void ef::Building::manualTargeting(std::shared_ptr<Object> target)
{
    for (int i = 0; i < (int)weapons.size(); i += 1)
        if (weapons[i].isManual())
            weapons[i].setNewTarget(target);
}

