// EFRITS
// project:     rts
// created on:  2024-02-29 - 15:24 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: refreshTarget implementation

#include "playerInfo.hh"

void ef::PlayerInfo::refreshTarget(std::shared_ptr<Unit> unit,
                                   std::vector<std::shared_ptr<Object>> targets)
{
    unit->changeTarget(targets);
}

