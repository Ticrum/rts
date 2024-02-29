// EFRITS
// project:     rts
// created on:  2024-02-29 - 12:18 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: building2 implementation

#include "building.hh"

ef::Building::Building(ConfBuilding conf,
                       Pos _pos,
                       int _objId,
                       int _alegence,
                       std::vector<ConfWeapon> & weaponsConf,
                       int actualHp,
                       std::vector<double> cdr)
    :
    Object(conf, _pos, _objId, _alegence, actualHp),
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
                weapons.emplace_back(weaponsConf[j], cdr[i]);
                j = weaponsConf.size() + 1;
            }
}

