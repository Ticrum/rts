// EFRITS
// project:     rts
// created on:  2024-02-13 - 15:36 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: computeActions implementation

#include "playerInfo.hh"

void ef::PlayerInfo::computeActions(double timePassed, std::vector<ConfWeapon> & weaponsConf)
{
    std::vector<std::shared_ptr<Object>> temp;

    for (int i = 0; i < (int)buildings.size(); i += 1)
        temp.push_back(otherUnits[i]);
    for (int i = 0; i < (int)buildings.size(); i += 1)
    {
        buildings[i]->makeTargeting(temp);
        if (buildings[i]->getType() == PRODUCTION)
        {
            std::shared_ptr<ProdBuilding> prod = std::static_pointer_cast<ProdBuilding>(buildings[i]);
            std::shared_ptr<Unit> newUnit = prod->produceUnit(timePassed, weaponsConf);
            if (newUnit.get() != nullptr)
                units.push_back(newUnit);
        }
        else if (buildings[i]->getType() == CONSTRUCT)
        {
            std::shared_ptr<ConstructBuilding> construct = std::static_pointer_cast<ConstructBuilding>(buildings[i]);
            std::shared_ptr<Building> newBuilding = construct->produceBuilding(timePassed, weaponsConf);
            if (newBuilding.get() != nullptr)
                producedBuilding.push_back(newBuilding);
        }
        else if (buildings[i]->getType() == TECH)
        {
            std::shared_ptr<TechBuilding> tech = std::static_pointer_cast<TechBuilding>(buildings[i]);
            std::shared_ptr<Tech> newTech = tech->searchTech(timePassed);
            if (newTech.get() != nullptr)
                searchedTech.push_back(newTech);
        }
    }
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

