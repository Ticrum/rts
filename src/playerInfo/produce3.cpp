// EFRITS
// project:     rts
// created on:  2024-02-16 - 17:07 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: produce3 implementation

#include "playerInfo.hh"

bool ef::PlayerInfo::produce(std::shared_ptr<ConstructBuilding> producer,
                             ConfBuilding newBuilding)
{
    if (money < newBuilding.cost)
        return false;
    money -= newBuilding.cost;
    producer->addBuildingToProd(newBuilding);
    return true;
}

