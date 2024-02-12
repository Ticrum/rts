// EFRITS
// project:     rts
// created on:  2024-02-12 - 16:53 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: playerinfo implementation

#include "playerInfo.hh"

ef::PlayerInfo::PlayerInfo()
    :
    money(0),
    moneyGain(0),
    totalEnergy(0),
    actualEnergy(0),
    map(64, 64),
    visionMap(64, 64),
    rallyPoint(nullptr)
{
}

