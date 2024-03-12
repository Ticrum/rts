// EFRITS
// project:     rts
// created on:  2024-02-27 - 15:45 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: produce implementation

#include "clientPlayerInfo.hh"

#include "iostream"

void ef::ClientPlayerInfo::produce(int producerId,
                                   std::string unitToProd,
                                   BuildingType type)
{
  std::cout << "!!!pass!!!" << std::endl;
  std::shared_ptr<Building> build = playerInfo.getBuild(producerId);
  if (build.get() == nullptr)
    return;
  std::cout << "!!!producer find!!!" << std::endl;
  Packet pack;
  pack.type = PRODUCE;
  pack.produce.producerId = build->getId();
  pack.produce.len = build->getConf().size();
  memcpy(pack.produce.conf, (char *)&build->getConf()[0], build->getConf().size());
  pack.produce.buildType = type;
  bool hasProduced = false;
  if (type == PRODUCTION)
    {
      std::shared_ptr<ProdBuilding> pBuild = std::static_pointer_cast<ProdBuilding>(build);
      ConfUnit conf = res.getUnit(unitToProd);
      hasProduced = playerInfo.produce(pBuild, conf);
    }
  else if (type == CONSTRUCT)
    {
      std::shared_ptr<ConstructBuilding> cBuild = std::static_pointer_cast<ConstructBuilding>(build);
      ConfBuilding conf = res.getBuild(unitToProd);
      hasProduced = playerInfo.produce(cBuild, conf);
    }
  else if (type == TECH)
    {
      std::shared_ptr<TechBuilding> tBuild = std::static_pointer_cast<TechBuilding>(build);
      Tech tech = res.getTech(unitToProd);
      hasProduced = playerInfo.produce(tBuild, tech);
    }
  if (hasProduced)
    clientUdp->sendData((char *)&pack, sizeof(Packet), serverConnected);
}

