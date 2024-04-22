// EFRITS
// project:     rts
// created on:  2024-02-27 - 17:38 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: destroyBuilding2 implementation

#include "clientPlayerInfo.hh"

bool ef::ClientPlayerInfo::destroyBuilding(int buildingId,
                                           bool isOther)
{
    std::shared_ptr<Building> tempBuilding;
    if (!isOther)
      tempBuilding = playerInfo.getBuild(buildingId, isOther);
    else
        tempBuilding = std::static_pointer_cast<Building>(playerInfo.getOtherObject(buildingId, false));
    return playerInfo.destroyBuilding(tempBuilding, isOther);
}

