// EFRITS
// project:     rts
// created on:  2024-02-14 - 11:39 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: makePath implementation

#include "playerInfo.hh"

void ef::PlayerInfo::makePath(std::shared_ptr<Unit> unit,
                              Pos dest,
                              MoveType moveType)
{
  Map tempMap(map.getMapSize().x, map.getMapSize().y);
  for (int i = 0; i < map.getMapSize().x * map.getMapSize().y; i += 1)
    {
      tempMap[i] = 0;
      if (map[i] != 0 || buildingMap[i] == 1)
	tempMap[i] = 1;
    }
  path.resetMap(tempMap);
  unit->changePath(path.makePath(unit->getActualPos(), dest), moveType);
}

