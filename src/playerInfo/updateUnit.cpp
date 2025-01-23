// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 03/05/2024 10:53:18 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "playerInfo.hh"

void ef::PlayerInfo::updateUnit(int unitId,
				std::shared_ptr<UdpConnect> udp,
				struct sockaddr_in client)
{
  std::shared_ptr<Unit> newUnit = getUnit(unitId, true);
  if (newUnit.get() == nullptr)
    {
      PacketDestroy tempPack;
      
      tempPack.type = DESTROY;
      tempPack.datalen = sizeof(PacketDestroy);
      tempPack.unitId = unitId;
      tempPack.isOther = true;
      tempPack.isBuilding = false;
      udp->sendData((char *)&tempPack, tempPack.datalen, client);
    }
  else
    {
      PacketAddOtherUnit pack;
      //std::cout << "updateOtherUnit pass GOOD  port : " << ntohs(client.sin_port) << " id : " << newUnit[i]->getId() << std::endl;
      pack.type = ADDOTHERUNIT;
      pack.datalen = sizeof(PacketAddOtherUnit);
      pack.unitId = newUnit->getId();
      pack.isOther = true;
      pack.alegence = newUnit->getAlegence();
      pack.posi = newUnit->getActualPos(0).get();
      memcpy(pack.conf, &newUnit->getConf()[0], newUnit->getConf().size());
      pack.len = newUnit->getConf().size();
      pack.actualHp = newUnit->getHp();
      pack.progress = newUnit->getProgress();
      pack.actualIndex = 0;//newUnit[i]->getActualIndex();
      pack.moveType = newUnit->getMoveType();
      std::vector<ConformPos> newPos = newUnit->getPathLeft();
      for (int j = 0; j < (int)newPos.size(); j += 1)
	pack.pos[j] = newPos[j];
      pack.nbrPos = newPos.size();
      std::vector<double> weaponCd = newUnit->getWeaponsCd();
      for (int j = 0; j < (int)weaponCd.size(); j += 1)
	pack.cdr[j] = weaponCd[j];
      pack.nbrCdr = weaponCd.size();
      pack.isUpdating = true;
      udp->sendData((char *)&pack, pack.datalen, client);
    }
}

