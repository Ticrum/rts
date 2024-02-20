// EFRITS
// project:     rts
// created on:  2024-02-13 - 12:52 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: isInVision implementation

#include "playerInfo.hh"

bool ef::PlayerInfo::isInVision(std::shared_ptr<Object> obj)
{
    return visionMap[obj->getPos().x + obj->getPos().y * visionMap.getMapSize().x] == 2;
}

