// EFRITS
// project:     rts
// created on:  2024-02-13 - 17:14 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: finishAction implementation

#include "playerInfo.hh"

void ef::PlayerInfo::finishAction(double timePassed)
{
    for (int i = 0; i < (int)buildings.size(); i += 1)
        buildings[i]->fireAllWeapon(timePassed);
    for (int i = 0; i < (int)units.size(); i += 1)
        units[i]->fireAllWeapon(timePassed);
    for (int i = 0; i < (int)buildings.size(); i += 1)
        if (buildings[i]->getHp() <= 0)
            killList.push_back(buildings[i]);
    for (int i = 0; i < (int)units.size(); i += 1)
        if (units[i]->getHp() <= 0)
            killList.push_back(units[i]);
}

