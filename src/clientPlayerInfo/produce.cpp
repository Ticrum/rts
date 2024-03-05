// EFRITS
// project:     rts
// created on:  2024-02-27 - 15:45 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: produce implementation

#include "clientPlayerInfo.hh"

void ef::ClientPlayerInfo::produce(int producerId,
                                   std::string unitToProd,
                                   BuildingType type)
{
    std::shared_ptr<Building> build = playerInfo.getBuild(producerId);
    Packet pack;
    pack.type = PRODUCE;
    pack.produce.producerId = build->getId();
    pack.produce.len = build->getConf().size();
    memcpy(pack.produce.conf, (char *)&build->getConf()[0], build->getConf().size());
    pack.produce.buildType = type;
    clientUdp->sendData((char *)&pack, sizeof(Packet), serverConnected);
    if (type == PRODUCTION)
    {
        std::shared_ptr<ProdBuilding> pBuild = std::static_pointer_cast<ProdBuilding>(build);
        ConfUnit conf = res.getUnit(unitToProd);
        playerInfo.produce(pBuild, conf);
    }
    else if (type == CONSTRUCT)
    {
        std::shared_ptr<ConstructBuilding> cBuild = std::static_pointer_cast<ConstructBuilding>(build);
        ConfBuilding conf = res.getBuild(unitToProd);
        playerInfo.produce(cBuild, conf);
    }
    else if (type == TECH)
    {
        std::shared_ptr<TechBuilding> tBuild = std::static_pointer_cast<TechBuilding>(build);
        Tech tech = res.getTech(unitToProd);
        playerInfo.produce(tBuild, tech);
    }
}

