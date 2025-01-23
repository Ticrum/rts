// EFRITS
// project:     rts
// created on:  2024-02-20 - 10:48 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: placeBuilding implementation

#include "serverPlayersInfo.hh"

void ef::ServerPlayersInfo::placeBuilding(Pos pos,
                                          int playerId)
{
  std::shared_ptr<Building> newBuilding;
  if ((newBuilding = playersInfo[playerId]->placeBuilding(pos)) != nullptr)
    {
      PacketAddOtherBuilding pack;
      pack.type = ADDOTHERBUILDING;
      pack.datalen = sizeof(PacketAddOtherBuilding);
      pack.buildId = newBuilding->getId();
      pack.alegence = newBuilding->getAlegence();
      pack.posi = newBuilding->getPos().get();
      pack.actualHp = newBuilding->getHp();
      pack.isActive = true;
      std::vector<double> tempCdr = newBuilding->getWeaponsCd();
      pack.nbrCdr = tempCdr.size();
      for (int i = 0; i < (int)tempCdr.size(); i += 1)
	pack.cdr[i] = tempCdr[i];
      pack.isOther = false;
      pack.len = newBuilding->getConf().size();
      memcpy(pack.conf, &newBuilding->getConf()[0], newBuilding->getConf().size());
      serverUdp->loop();
      serverUdp->sendData((char *)&pack, pack.datalen, clientConnected[playerId]);
    }
}

