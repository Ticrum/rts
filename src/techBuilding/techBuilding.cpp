// EFRITS
// project:     rts
// created on:  2024-02-12 - 15:21 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: techBuilding implementation

#include "building.hh"

ef::TechBuilding::TechBuilding(ConfBuilding conf,
			       std::shared_ptr<ef::Bpixelarray>_img,
			       Pos _pos,
                               int _objId,
                               int _alegence,
                               std::vector<ConfWeapon> & weaponsConf,
			       std::vector<ConfObj> & shotConf)
  :
  Building(conf, _img, _pos, _objId, _alegence, weaponsConf, shotConf),
  timeLeft(0),
  onHold(false)
{
}

