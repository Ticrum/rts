// EFRITS
// project:     rts
// created on:  2024-02-22 - 11:55 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: getVisionMap implementation

#include "playerInfo.hh"

#include <iostream>

ef::Map & ef::PlayerInfo::getVisionMap()
{
  std::cout << (int)visionMap[visionMap.getMapSize().x - 7 + 4 * visionMap.getMapSize().x] << (int)visionMap[visionMap.getMapSize().x - 6 + 4 * visionMap.getMapSize().x] << (int)visionMap[visionMap.getMapSize().x - 5 + 4 * visionMap.getMapSize().x] << std::endl;
  std::cout << (int)visionMap[visionMap.getMapSize().x - 7 + 5 * visionMap.getMapSize().x] << (int)visionMap[visionMap.getMapSize().x - 6 + 5 * visionMap.getMapSize().x] << (int)visionMap[visionMap.getMapSize().x - 5 + 5 * visionMap.getMapSize().x] << std::endl;
  std::cout << (int)visionMap[visionMap.getMapSize().x - 7 + 6 * visionMap.getMapSize().x] << (int)visionMap[visionMap.getMapSize().x - 6 + 6 * visionMap.getMapSize().x] << (int)visionMap[visionMap.getMapSize().x - 5 + 6 * visionMap.getMapSize().x] << std::endl;
  return visionMap;
}

