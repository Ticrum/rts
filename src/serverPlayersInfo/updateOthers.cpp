// EFRITS
// project:     rts
// created on:  2024-02-22 - 11:06 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: updateOther implementation

#include "serverPlayersInfo.hh"

void ef::ServerPlayersInfo::updateOther()
{
  for (int i = 0; i < (int)playersInfo.size(); i += 1)
    {
      playersInfo[i]->updateOther();
      for (int j = i + 1; j < (int)playersInfo.size() + i; j += 1)
        {
	  playersInfo[i]->updateOther(playersInfo[j % (int)playersInfo.size()]->getUnitInVision(playersInfo[i]->getVisionMap()), serverUdp, clientConnected[i]);
	  playersInfo[i]->updateOther(playersInfo[j % (int)playersInfo.size()]->getBuildingInVision(playersInfo[i]->getVisionMap()), serverUdp, clientConnected[i]);
        }
    }
}

