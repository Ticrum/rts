// EFRITS
// project:     rts
// created on:  2024-02-22 - 12:02 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: updateOther2 implementation

#include "playerInfo.hh"

//#include <iostream>

void ef::PlayerInfo::updateOther(std::vector<std::shared_ptr<Unit>> newUnit,
                                 std::shared_ptr<UdpConnect> udp,
                                 struct sockaddr_in client)
{
  for (int i = 0; i < (int)newUnit.size(); i += 1)
    {
      bool hasFind = false;
      //std::cout << "updateOtherUnit othUnitSize : " << otherUnits.size() << std::endl;
      for (int j = 0; j < (int)otherUnits.size(); j += 1)
	if (otherUnits[j]->getId() == newUnit[i]->getId())
	  {
	    //std::cout << "updateOtherUnit pass in same x : " << newUnit[i]->getPos().x << " y : " << newUnit[i]->getPos().y << " id : " << newUnit[i]->getId() << std::endl;
	    hasFind = true;
	    break;
	  }
      if (!hasFind)
        {
	  PacketAddOtherUnit pack;
	  //std::cout << "updateOtherUnit pass GOOD  port : " << ntohs(client.sin_port) << " id : " << newUnit[i]->getId() << std::endl;
	  pack.type = ADDOTHERUNIT;
	  pack.datalen = sizeof(PacketAddOtherUnit);
	  pack.unitId = newUnit[i]->getId();
	  pack.isOther = true;
	  pack.alegence = newUnit[i]->getAlegence();
	  pack.posi = newUnit[i]->getActualPos(0).get();
	  memcpy(pack.conf, &newUnit[i]->getConf()[0], newUnit[i]->getConf().size());
	  pack.len = newUnit[i]->getConf().size();
	  pack.actualHp = newUnit[i]->getHp();
	  pack.progress = newUnit[i]->getProgress();
	  pack.actualIndex = 0;//newUnit[i]->getActualIndex();
	  pack.moveType = newUnit[i]->getMoveType();
	  std::vector<ConformPos> newPos = newUnit[i]->getPathLeft();
	  for (int j = 0; j < (int)newPos.size(); j += 1)
	    pack.pos[j] = newPos[j];
	  pack.nbrPos = newPos.size();
	  std::vector<double> weaponCd = newUnit[i]->getWeaponsCd();
	  for (int j = 0; j < (int)weaponCd.size(); j += 1)
	    pack.cdr[j] = weaponCd[j];
	  pack.nbrCdr = weaponCd.size();
	  pack.isUpdating = false;
	  udp->sendData((char *)&pack, pack.datalen, client);
	  addOther(newUnit[i], true);
        }
    }
  //std::cout << "updateOtherUnit othUnitSize2 : " << otherUnits.size() << std::endl;
}

