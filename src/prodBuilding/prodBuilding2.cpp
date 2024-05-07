// EFRITS
// project:     rts
// created on:  2024-02-29 - 16:15 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: prodBuilding implementation

#include "building.hh"

ef::ProdBuilding::ProdBuilding(ConfBuilding conf,
			       std::shared_ptr<ef::Bpixelarray>_img,
                               Pos _pos,
                               int _objId,
                               int _alegence,
                               std::vector<ConfWeapon> & weaponsConf,
			       std::vector<ConfObj> & shotConf,
                               int actualHp,
                               std::vector<double> cdr)
  :
  Building(conf, _img, _pos, _objId, _alegence, weaponsConf, shotConf, actualHp, cdr)
{
}

