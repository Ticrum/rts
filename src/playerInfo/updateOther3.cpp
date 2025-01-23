// EFRITS
// project:     rts
// created on:  2024-02-22 - 12:02 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: updateOther2 implementation

#include "playerInfo.hh"

//#include <iostream>

void ef::PlayerInfo::updateOther(std::vector<std::shared_ptr<Building>> newBuilding,
                                 std::shared_ptr<UdpConnect> udp,
                                 struct sockaddr_in client)
{
  for (int i = 0; i < (int)newBuilding.size(); i += 1)
    {
      bool hasFind = false;
      for (int j = 0; j < (int)otherBuildings.size(); j += 1)
	if (otherBuildings[j]->getId() == newBuilding[i]->getId())
	  {
	    //std::cout << "updateOther pass in same x : " << newBuilding[i]->getPos().x << " y : " << newBuilding[i]->getPos().y << std::endl;
	    hasFind = true;
	    break;
	  }
      if (!hasFind)
        {
	  PacketAddOtherBuilding pack;
	  //std::cout << "updateOther pass GOOD  port : " << ntohs(client.sin_port) << std::endl;
	  pack.type = ADDOTHERBUILDING;
	  pack.datalen = sizeof(PacketAddOtherBuilding);
	  pack.isOther = true;
	  pack.buildId = newBuilding[i]->getId();
	  pack.alegence = newBuilding[i]->getAlegence();
	  pack.posi = newBuilding[i]->getPos().get();
	  memcpy(pack.conf, &newBuilding[i]->getConf()[0], newBuilding[i]->getConf().size());
	  pack.len = newBuilding[i]->getConf().size();
	  pack.actualHp = newBuilding[i]->getHp();
	  pack.isActive = newBuilding[i]->getIsActive();
	  std::vector<double> weaponCd = newBuilding[i]->getWeaponsCd();
	  for (int j = 0; j < (int)weaponCd.size(); j += 1)
	    pack.cdr[j] = weaponCd[j];
	  pack.nbrCdr = weaponCd.size();
	  udp->sendData((char *)&pack, sizeof(Packet), client);
	  addOther(newBuilding[i], true);
        }
    }
}
