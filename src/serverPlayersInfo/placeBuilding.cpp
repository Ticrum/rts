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
      Packet pack;
      pack.type = ADDOTHERBUILDING;
      pack.addOtherBuilding.buildId = newBuilding->getId();
      pack.addOtherBuilding.alegence = newBuilding->getAlegence();
      pack.addOtherBuilding.posi = newBuilding->getPos().get();
      pack.addOtherBuilding.actualHp = newBuilding->getHp();
      pack.addOtherBuilding.isActive = true;
      std::vector<double> tempCdr = newBuilding->getWeaponsCd();
      pack.addOtherBuilding.nbrCdr = tempCdr.size();
      for (int i = 0; i < (int)tempCdr.size(); i += 1)
	pack.addOtherBuilding.cdr[i] = tempCdr[i];
      pack.addOtherBuilding.isOther = false;
      pack.addOtherBuilding.len = newBuilding->getConf().size();
      memcpy(pack.addOtherBuilding.conf, &newBuilding->getConf()[0], newBuilding->getConf().size());
      serverUdp->loop();
      serverUdp->sendData((char *)&pack, sizeof(Packet), clientConnected[playerId]);
    }
}

