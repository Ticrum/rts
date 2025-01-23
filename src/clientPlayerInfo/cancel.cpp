// EFRITS
// project:     rts
// created on:  2024-02-27 - 15:45 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: produce implementation

#include "clientPlayerInfo.hh"

#include <iostream>

void ef::ClientPlayerInfo::cancel(int producerId,
				  BuildingType type)
{
  //std::cout << "!!!pass type : " << type << "!!!!" << std::endl;
  std::shared_ptr<Building> build = playerInfo.getBuild(producerId, false);
  if (build.get() == nullptr)
    return;
  //std::cout << "!!!producer find!!!" << std::endl;
  PacketCancel pack;
  pack.type = CANCEL;
  pack.datalen = sizeof(PacketCancel);
  pack.producerId = build->getId();
  pack.buildType = type;
  if (type == PRODUCTION)
    {
      std::shared_ptr<ProdBuilding> pBuild = std::static_pointer_cast<ProdBuilding>(build);
      playerInfo.cancel(pBuild);
    }
  else if (type == CONSTRUCT)
    {
      std::shared_ptr<ConstructBuilding> cBuild = std::static_pointer_cast<ConstructBuilding>(build);
      playerInfo.cancel(cBuild);
    }
  else if (type == TECH)
    {
      std::shared_ptr<TechBuilding> tBuild = std::static_pointer_cast<TechBuilding>(build);
      playerInfo.cancel(tBuild);
    }
  //std::cout << "/////// HAS produced ////////" << std::endl;
  clientUdp->sendData((char *)&pack, pack.datalen, serverConnected);
}

void ef::ClientPlayerInfo::cancel()
{
  if ((int)selectedBuilding.size() > 0)
    cancel(selectedBuilding[0]->getId(), selectedBuilding[0]->getType());
}

