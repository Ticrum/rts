// EFRITS
// project:     rts
// created on:  2024-02-27 - 16:54 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: destroyUnit2 implementation

#include "clientPlayerInfo.hh"

bool ef::ClientPlayerInfo::destroyUnit(int unitId,
                                       bool isOther)
{
    std::shared_ptr<Unit> tempUnit;
    if (!isOther)
      tempUnit = playerInfo.getUnit(unitId, isOther);
    else
        tempUnit = std::static_pointer_cast<Unit>(playerInfo.getOtherObject(unitId, false));
    return playerInfo.destroyUnit(tempUnit, isOther);
}

