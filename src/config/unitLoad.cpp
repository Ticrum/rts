#include "unit.hh"
#include "Bconf.hh"

int ef::ConfUnit::load(std::string &file)
{
    Bconf conf(file);
    if(conf())
        for(unsigned int i = 0; i < 10 && conf.retry(file); i++);
    if(conf())
        return 1;
    int tmp = LoadBasic(conf);
    char *buf;
    if(tmp > 0)
        return tmp;
    if(!bunny_configuration_getf_int(conf.Get(), &cost, "Unit.cost"))
        return 10;
    if(!bunny_configuration_getf_double(conf.Get(), &speed, "Unit.speed"))
        return 11;
    if(!bunny_configuration_getf_double(conf.Get(), &runningSpeed, "Unit.runningSpeed"))
        return 12;
    if(!bunny_configuration_getf_string(conf.Get(), (const char **)&buf, "Unit.moveType"))
        return 13;
    switch(buf[0])
    {
    case 'R':
        moveType = RUN;
        break;
    case 'W':
        moveType = WALK;
        break;
    case 'S':
        moveType = STATIC;
        break;
    default:
        return 17;
    }
    if(!bunny_configuration_getf_string(conf.Get(), (const char **)&buf, "Unit.isFlying"))
        return 14;
    switch(buf[0])
    {
    case 'T':
        isFlying = true;
        break;
    case 'F':
        isFlying = false;
        break;
    default:
        return 18;
    }
    if(!bunny_configuration_getf_double(conf.Get(), &timeToProduce, "Unit.timeToProduce"))
        return 15;
    int size;
    if(!bunny_configuration_getf_int(conf.Get(), &size, "Unit.weaponConf.size"))
        return 16;
    if(!weaponConf.empty())
        weaponConf.clear();
    for(int i = 0; i < size; i++)
    {
        if(!bunny_configuration_getf_string(conf.Get(), (const char **)&buf, "Unit.weaponConf.data[%d]",i))
            return 101+i;
        weaponConf.push_back(std::string(buf));
    }
    return 0;
}
