// EFRITS
// project:     rts
// created on:  2024-02-12 - 15:21 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: techBuilding implementation

#include "building.hh"

ef::TechBuilding::TechBuilding(ConfBuilding conf,
                               Pos _pos,
                               int _objId,
                               int _alegence,
                               std::vector<ConfWeapon> & weaponsConf)
    :
    Building(conf, _pos, _objId, _alegence, weaponsConf)
{
}

