// EFRITS
// project:     rts
// created on:  2024-02-29 - 16:20 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: techBuilding implementation

#include "building.hh"

ef::TechBuilding::TechBuilding(ConfBuilding conf,
                               Pos _pos,
                               int _objId,
                               int _alegence,
                               std::vector<ConfWeapon> & weaponsConf,
                               int actualHp,
                               std::vector<double> cdr)
    :
    Building(conf, _pos, _objId, _alegence, weaponsConf, actualHp, cdr)
{
}

