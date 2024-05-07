// EFRITS
// project:     rts
// created on:  2024-02-20 - 11:04 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: addOther implementation

#include "serverPlayersInfo.hh"

void ef::ServerPlayersInfo::addOther(int buildId,
                                     std::string build,
                                     Pos pos,
                                     int playerId,
                                     BuildingType type)
{
    std::shared_ptr<Building> tempBuild;
    ConfBuilding conf = res.getBuild(build);
    std::map<std::string, std::shared_ptr<Bpixelarray>> &tmp = res.getSprit();
    
    if (type == PRODUCTION)
      tempBuild.reset(new ProdBuilding(conf, tmp[conf.img], pos, buildId, playerId, res.getWeaponConf(), res.getShotConf())); //get weapon conf
    if (type == CONSTRUCT)
      tempBuild.reset(new ConstructBuilding(conf, tmp[conf.img], pos, buildId, playerId, res.getWeaponConf(), res.getShotConf())); //get weapon conf
    if (type == TECH)
      tempBuild.reset(new TechBuilding(conf, tmp[conf.img], pos, buildId, playerId, res.getWeaponConf(), res.getShotConf())); //get weapon conf
    else
      tempBuild.reset(new Building(conf, tmp[conf.img], pos, buildId, playerId, res.getWeaponConf(), res.getShotConf()));
    playersInfo[playerId]->addOther(tempBuild, false);
}

