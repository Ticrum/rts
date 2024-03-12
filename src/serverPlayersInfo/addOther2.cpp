// EFRITS
// project:     rts
// created on:  2024-02-20 - 11:54 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: addOther2 implementation

#include "serverPlayersInfo.hh"

void ef::ServerPlayersInfo::addOther(int unitId,
                                     std::string unit,
                                     Pos pos,
                                     int playerId)
{
    std::shared_ptr<Unit> tempUnit;
    ConfUnit conf = res.getUnit(unit);
    std::map<std::string, std::shared_ptr<Bpixelarray>> &tmp = res.getSprit();
    tempUnit.reset(new Unit(conf, tmp[conf.img], pos, unitId, playerId, res.getWeaponConf()));
    playersInfo[playerId]->addOther(tempUnit, true);
}

