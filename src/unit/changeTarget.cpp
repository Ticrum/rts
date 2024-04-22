// EFRITS
// project:     rts
// created on:  2024-02-29 - 15:42 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: changeTarget implementation

#include "unit.hh"

void ef::Unit::changeTarget(std::vector<std::shared_ptr<Object>> targets)
{
    for (int i = 0; i < (int)weapons.size(); i += 1)
      weapons[i].setNewTarget(targets[i], false);
}

