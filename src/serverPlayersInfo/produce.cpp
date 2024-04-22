// EFRITS
// project:     rts
// created on:  2024-02-20 - 12:15 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: produce implementation

#include "serverPlayersInfo.hh"

void ef::ServerPlayersInfo::produce(int producerId,
                                    std::string unitToProd,
                                    int playerId,
                                    BuildingType type)
{
  std::shared_ptr<Building> build = playersInfo[playerId]->getBuild(producerId, false);
    if (type == PRODUCTION)
    {
        std::shared_ptr<ProdBuilding> pBuild = std::static_pointer_cast<ProdBuilding>(build);
        ConfUnit conf = res.getUnit(unitToProd);
        playersInfo[playerId]->produce(pBuild, conf);
    }
    else if (type == CONSTRUCT)
    {
        std::shared_ptr<ConstructBuilding> cBuild = std::static_pointer_cast<ConstructBuilding>(build);
        ConfBuilding conf = res.getBuild(unitToProd);
        playersInfo[playerId]->produce(cBuild, conf);
    }
    else if (type == TECH)
    {
        std::shared_ptr<TechBuilding> tBuild = std::static_pointer_cast<TechBuilding>(build);
        Tech tech = res.getTech(unitToProd);
        playersInfo[playerId]->produce(tBuild, tech);
    }
}

