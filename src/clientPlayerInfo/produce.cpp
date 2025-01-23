// EFRITS
// project:     rts
// created on:  2024-02-27 - 15:45 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: produce implementation

#include "clientPlayerInfo.hh"

#include <iostream>

void ef::ClientPlayerInfo::produce(int producerId,
                                   std::string unitToProd,
                                   BuildingType type)
{
  //std::cout << "!!!pass type : " << type << "!!!!" << std::endl;
  std::shared_ptr<Building> build = playerInfo.getBuild(producerId, false);
  if (build.get() == nullptr)
    return;
  //std::cout << "!!!producer find!!!" << std::endl;
  PacketProduce pack;
  pack.type = PRODUCE;
  pack.datalen = sizeof(PacketProduce);
  pack.producerId = build->getId();
  pack.len = unitToProd.size();
  memcpy(pack.conf, (char *)&unitToProd[0], unitToProd.size());
  pack.buildType = type;
  bool hasProduced = false;
  if (type == PRODUCTION)
    {
      std::shared_ptr<ProdBuilding> pBuild = std::static_pointer_cast<ProdBuilding>(build);
      ConfUnit conf = res.getUnit(unitToProd);
      if (conf.maxhp >= 0)
	hasProduced = playerInfo.produce(pBuild, conf);
      else
	std::cout << "produce in clientplayerinfo BAD CONF" << std::endl;
    }
  else if (type == CONSTRUCT)
    {
      std::shared_ptr<ConstructBuilding> cBuild = std::static_pointer_cast<ConstructBuilding>(build);
      ConfBuilding conf = res.getBuild(unitToProd);
      if (conf.maxhp >= 0)
	hasProduced = playerInfo.produce(cBuild, conf);
      else
	std::cout << "produce in clientplayerinfo BAD CONF" << std::endl;
    }
  else if (type == TECH)
    {
      std::shared_ptr<TechBuilding> tBuild = std::static_pointer_cast<TechBuilding>(build);
      Tech tech = res.getTech(unitToProd);
      hasProduced = playerInfo.produce(tBuild, tech);
    }
  //std::cout << "/////// HAS produced ////////" << std::endl;
  if (hasProduced)
    clientUdp->sendData((char *)&pack, sizeof(Packet), serverConnected);
}

void ef::ClientPlayerInfo::produce(std::string unitToProd)
{
  for(int i = 0; i < (int)selectedBuilding.size(); i += 1)
    produce(selectedBuilding[i]->getId(), unitToProd, selectedBuilding[i]->getType());
}

