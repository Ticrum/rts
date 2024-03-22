// EFRITS
// project:     rts
// created on:  2024-02-29 - 12:27 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: unit2 implementation

#include "unit.hh"

ef::Unit::Unit(ConfUnit conf,
               std::shared_ptr<ef::Bpixelarray> _img,
	       Pos _pos,
               int _objId,
               int _alegence,
               std::vector<ConfWeapon> & weaponsConf,
               int actualHp,
               double _progress,
	       int _actualIndex,
               MoveType type,
               std::vector<Pos> newPath,
               std::vector<double> cdr)
  :
  Object(conf, _img, _pos, _objId, _alegence, actualHp),
  path(newPath),
  actualIndex(_actualIndex),
  progress(_progress),
  speed(conf.speed),
  runningSpeed(conf.runningSpeed),
  moveType(type),
  isFlying(conf.isFlying)
{
  for (int i = 0; i < (int)conf.weaponConf.size(); i += 1)
    for (int j = 0; j < (int)weaponsConf.size(); j += 1)
      if (conf.weaponConf[i] == weaponsConf[j].conf)
	{
	  weapons.emplace_back(weaponsConf[j], alegence, cdr[i]);
	  j = weaponsConf.size() + 1;
	}
}

