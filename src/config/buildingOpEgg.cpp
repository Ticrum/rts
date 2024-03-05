#include "building.hh"

ef::ConfBuilding &ef::ConfBuilding::operator=(ConfBuilding const&other)
{
    cost= other.cost;
    timeToProduce= other.timeToProduce;
    type= other.type;
    canBeTarget= other.canBeTarget;
    energyCost= other.energyCost;
    energyProduction= other.energyProduction;
    moneyProduction= other.moneyProduction;
    weaponConf= other.weaponConf;
    ConfObj::operator=(other);
    return *this;
}
