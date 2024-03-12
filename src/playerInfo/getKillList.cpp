// EFRITS
// project:     rts
// created on:  2024-02-16 - 10:58 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: getKillList implementation

#include "playerInfo.hh"

std::vector<ef::Killed> & ef::PlayerInfo::getKillList()
{
    return killList;
}

