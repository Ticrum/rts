// EFRITS
// project:     rts
// created on:  2024-02-23 - 11:21 +0100
// 1st author:  romain.piccoche - romain.picoche
// description: load config object

#include "object.hh"
#include "Bconf.hh"

int ef::ConfObj::LoadBasic(ef::Bconf &conff)
{
    char *buf;

    if(!bunny_configuration_getf_string(conff.Get(), (const char **)&buf, "Object.name"))
        return 2;
    conf.clear();
    conf.insert(0, buf);
    if(conf.size() >= 128)
        return 3;
    unsigned int i = 0;
    while(i< conf.size())
    {
        conformConf[i] = conf[i];
        i++;
    }
    conformConf[i] = '\0';
    if(!bunny_configuration_getf_int(conff.Get(), &imgId, "Object.imgId"))
        return 4;
    if(!bunny_configuration_getf_int(conff.Get(), &objSize.x, "Object.objSize.x"))
        return 5;
    if(!bunny_configuration_getf_int(conff.Get(), &objSize.y, "Object.objSize.y"))
        return 6;
    if(!bunny_configuration_getf_int(conff.Get(), &maxhp, "Object.maxHp"))
        return 7;
    if(!bunny_configuration_getf_int(conff.Get(), &armor, "Object.armor"))
        return 8;
    if(!bunny_configuration_getf_int(conff.Get(), &rangeOfVision, "Object.rangeOfVision"))
        return 9;
    return 0;
}