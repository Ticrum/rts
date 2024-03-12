// EFRITS
// project:     rts
// created on:  2024-02-20 - 10:48 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: placeBuilding implementation

#include "serverPlayersInfo.hh"

void ef::ServerPlayersInfo::placeBuilding(Pos pos,
                                          int playerId)
{
  playersInfo[playerId]->placeBuilding(pos);
}

