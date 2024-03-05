// EFRITS
// project:     rts
// created on:  2024-02-23 - 14:00 +0100
// 1st author:  romain.piccoche - romain.picoche
// description: load Building conf

#include "building.hh"
#include "Bconf.hh"

int ef::ConfBuilding::load(std::string &file)
{
    Bconf conf(file);
    if(conf())
        for(unsigned int i = 0; i < 10 && conf.retry(file); i++);
    if(conf())
        return 1;
    char buf = LoadBasic(conf);
    if(buf > 0)
        return buf;
    if(!bunny_configuration_getf_int(conf.Get(), &cost, "Building.cost"))
        return 10;
    if(!bunny_configuration_getf_double(conf.Get(), &timeToProduce, "Building.timeToProduce"))
        return 11;
    char *zut;
    if(!bunny_configuration_getf_string(conf.Get(), (const char **)&zut, "Building.type"))
        return 12;
    switch (zut[0])
    {
    case 'P':
        type = PRODUCTION;
        break;
    case 'C':
        type = CONSTRUCT;
        break;
    case 'D':
        type = DEFENCE;
        break;
    case 'T':
        type = TECH;
        break;
    case 'E':
        type = ENERGY;
        break;
    case 'M':
        type = MONEY;
        break;
    default:
        return 18;
    }
    if(!bunny_configuration_getf_string(conf.Get(), (const char **)&zut, "Building.canBeTarget"))
        return 13;
    switch(zut[0])
    {
    case 'T':
        canBeTarget = true;
        break;
    case 'F':
        canBeTarget = false;
        break;
    default :
        return 19;
    }
    if(!bunny_configuration_getf_int(conf.Get(), &energyCost, "Building.energyCost"))
        return 14;
    if(!bunny_configuration_getf_int(conf.Get(), &energyProduction, "Building.energyProduction"))
        return 15;
    if(!bunny_configuration_getf_int(conf.Get(), &moneyProduction, "Building.moneyProduction"))
        return 16;
    int size;
    if(!bunny_configuration_getf_int(conf.Get(), &size, "Building.weaponConf.size"))
        return 17;
    if(!weaponConf.empty())
        weaponConf.clear();
    for(int i = 0; i < size; i++)
    {
        if(!bunny_configuration_getf_string(conf.Get(), (const char **)&zut, "Building.weaponConf.data[%d]",i))
            return 101+i;
        weaponConf.push_back(std::string(zut));
    }
    return 0;
}
