// EFRITS
// project:     rts
// created on:  2024-02-12 - 11:20 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: building implementation

#include "building.hh"

ef::Building::Building(ConfBuilding conf,
                       std::shared_ptr<ef::Bpixelarray>_img,
		       Pos _pos,
                       int _objId,
                       int _alegence,
                       std::vector<ConfWeapon> & weaponsConf)
  :
  Object(conf, _img, _pos, _objId, _alegence),
  type(conf.type),
  canBeTarget(conf.canBeTarget),
  energyCost(conf.energyCost),
  energyProduction(conf.energyProduction),
  moneyProduction(conf.moneyProduction),
  isActive(true)
{
  for (int i = 0; i < (int)conf.weaponConf.size(); i += 1)
    for (int j = 0; j < (int)weaponsConf.size(); j += 1)
      if (conf.weaponConf[i] == weaponsConf[j].conf)
	{
	  weapons.emplace_back(weaponsConf[j], alegence);
	  j = weaponsConf.size() + 1;
	}
}

