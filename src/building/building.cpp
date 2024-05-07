// EFRITS
// project:     rts
// created on:  2024-02-12 - 11:20 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: building implementation

#include "building.hh"

#include <iostream>

ef::Building::Building(ConfBuilding conf,
                       std::shared_ptr<ef::Bpixelarray>_img,
		       Pos _pos,
                       int _objId,
                       int _alegence,
                       std::vector<ConfWeapon> & weaponsConf,
		       std::vector<ConfObj> & shotConf)
  :
  Object(conf, _img, _pos, _objId, _alegence),
  type(conf.type),
  canBeTarget(conf.canBeTarget),
  energyCost(conf.energyCost),
  energyProduction(conf.energyProduction),
  moneyProduction(conf.moneyProduction),
  isActive(true),
  butons(conf.butons),
  groupButon(0)
{
  std::cout << "building construct" << std::endl;
  for (int i = 0; i < (int)conf.weaponConf.size(); i += 1)
    for (int j = 0; j < (int)weaponsConf.size(); j += 1)
      if (conf.weaponConf[i] == weaponsConf[j].conf)
	{
	  for (int k = 0; k < (int)shotConf.size(); k += 1)
	    if (weaponsConf[j].ShotConf == shotConf[k].conf)
	    {
	      weapons.emplace_back(weaponsConf[j], alegence, shotConf[k]);
	      k = shotConf.size() + 1;
	    }
	  j = weaponsConf.size() + 1;
	}
}

