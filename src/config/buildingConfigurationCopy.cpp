// EFRITS
// project:     rts
// created on:  2024-02-26 - 11:51 +0100
// 1st author:  romain.piccoche - romain.picoche
// description: contructor by copy

#include "building.hh"

ef::ConfBuilding::ConfBuilding(ef::ConfBuilding const &other)
    :ConfObj((ConfObj const &)other),
     cost(other.cost),
     timeToProduce(other.timeToProduce),
     type(other.type),
     canBeTarget(other.canBeTarget),
     energyCost(other.energyCost),
     energyProduction(other.energyProduction),
     moneyProduction(other.moneyProduction),
     butons(other.butons),
     weaponConf(other.weaponConf)
{}
