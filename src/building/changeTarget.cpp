// EFRITS
// project:     rts
// created on:  2024-02-29 - 15:55 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: changeTarget implementation

#include "building.hh"

void ef::Building::changeTarget(std::vector<std::shared_ptr<Object>> targets)
{
    for (int i = 0; i < (int)weapons.size(); i += 1)
        weapons[i].setNewTarget(targets[i]);
}

