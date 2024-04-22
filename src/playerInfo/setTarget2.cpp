// EFRITS
// project:     rts
// created on:  2024-02-28 - 10:47 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: setTarget2 implementation

#include "playerInfo.hh"

void ef::PlayerInfo::setTarget(std::shared_ptr<Building> build,
                               std::shared_ptr<Object> other,
			       bool isTargetBuild)
{
  build->manualTargeting(other, isTargetBuild);
}

