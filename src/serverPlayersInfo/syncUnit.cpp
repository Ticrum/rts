// EFRITS
// project:     rts
// created on:  2024-02-21 - 11:00 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: computeActions implementation

#include "serverPlayersInfo.hh"

void ef::ServerPlayersInfo::syncUnit(int unitId,
				     int alegence)
{
  playersInfo[alegence]->updateUnit(unitId, serverUdp, clientConnected[alegence]);
}

