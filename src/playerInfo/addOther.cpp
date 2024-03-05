// EFRITS
// project:     rts
// created on:  2024-02-13 - 12:38 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: addOther implementation

#include "playerInfo.hh"

void ef::PlayerInfo::addOther(std::shared_ptr<Unit> unit,
                              bool isOther)
{
    if (isOther)
        otherUnits.push_back(unit);
    else
        units.push_back(unit);
}

