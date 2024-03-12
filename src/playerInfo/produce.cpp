// EFRITS
// project:     rts
// created on:  2024-02-13 - 11:29 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: produce implementation

#include "playerInfo.hh"

bool ef::PlayerInfo::produce(std::shared_ptr<ProdBuilding> producer,
                             ConfUnit newUnit)
{
    if (money < newUnit.cost)
        return false;
    money -= newUnit.cost;
    producer->addUnitToProd(newUnit);
    return true;
}

