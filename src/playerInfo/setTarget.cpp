// EFRITS
// project:     rts
// created on:  2024-02-13 - 11:18 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: setTarget implementation

#include "playerInfo.hh"

void ef::PlayerInfo::setTarget(std::shared_ptr<Unit> unit,
                               std::shared_ptr<Object> other,
			       bool isTargetBuild)
{
  unit->manualTargeting(other, isTargetBuild);
}

