// EFRITS
// project:     rts
// created on:  2024-02-29 - 16:18 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: constructBuilding implementation

#include "building.hh"

ef::ConstructBuilding::ConstructBuilding(ConfBuilding conf,
					 std::shared_ptr<ef::Bpixelarray>_img,
                                         Pos _pos,
                                         int _objId,
                                         int _alegence,
                                         std::vector<ConfWeapon> & weaponsConf,
                                         int actualHp,
                                         std::vector<double> cdr)
  :
  Building(conf, _img, _pos, _objId, _alegence, weaponsConf, actualHp, cdr)
{
}

