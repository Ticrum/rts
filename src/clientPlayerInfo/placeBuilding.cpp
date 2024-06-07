// EFRITS
// project:     rts
// created on:  2024-02-27 - 13:06 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: placeBuilding implementation

#include "clientPlayerInfo.hh"

#include <iostream>

void ef::ClientPlayerInfo::placeBuilding(Pos pos)
{
  //playerInfo.placeBuilding(pos);
  std::cout << "placeBuilding clientplayerinfo pass " << std::endl;
  std::vector<std::shared_ptr<Building>> temp = playerInfo.getProducedBuilding();
  if (temp.size() > 0)
    {
      playerInfo.getProducedBuilding().clear();
      for (int i = 0; i < (int)temp.size() - 1; i += 1)
	playerInfo.getProducedBuilding().push_back(temp[i + 1]);
    }

  Packet pack;
  pack.type = PLACEBUILD;
  pack.placeBuild.pos = pos.get();
  clientUdp->sendData((char *)&pack, sizeof(Packet), serverConnected);
}

