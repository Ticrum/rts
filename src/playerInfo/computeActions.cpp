// EFRITS
// project:     rts
// created on:  2024-02-13 - 15:36 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: computeActions implementation

#include "playerInfo.hh"

void ef::PlayerInfo::computeActions(double timePassed)
{
    std::vector<std::shared_ptr<Object>> temp;

    for (int i = 0; i < (int)buildings.size(); i += 1)
        temp.push_back(otherUnits[i]);
    for (int i = 0; i < (int)buildings.size(); i += 1)
        buildings[i]->makeTargeting(temp);
    for (int i = 0; i < (int)units.size(); i += 1)
    {
        units[i]->makeTargeting(temp);
        units[i]->moveUnit(timePassed);
    }
    moneyCooldown -= timePassed;
    if (moneyCooldown <= 0)
    {
        money += moneyGain;
        moneyCooldown = 0.25;
    }
}

