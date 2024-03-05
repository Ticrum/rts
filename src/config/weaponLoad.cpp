// EFRITS
// project:     str
// created on:  2024-02-22 - 16:54 +0100
// 1st author:  romain.piccoche - romain.picoche
// description: load weapon configuration

#include "weapon.hh"
#include "Bconf.hh"

int ef::ConfWeapon::load(std::string &file)
{
    Bconf conff(file);
    if(conff())
        for(unsigned int i = 0; i < 10 && conff.retry(file); i++);
    if(conff())
        return 1;
    char *buf;
    if(!bunny_configuration_getf_string(conff.Get(), (const char **)&buf, "Weapon.name"))
        return 2;
    conf.clear();
    conf.insert(0, buf);
    if(!bunny_configuration_getf_int(conff.Get(), &dmg, "Weapon.dmg"))
        return 3;
    if(!bunny_configuration_getf_int(conff.Get(), &nbrAtt, "Weapon.nbrAtt"))
        return 4;
    if(!bunny_configuration_getf_double(conff.Get(), &cdrMax, "Weapon.cdrMax"))
        return 5;
    if(!bunny_configuration_getf_int(conff.Get(), &range, "Weapon.range"))
        return 6;
    if(!bunny_configuration_getf_string(conff.Get(), (const char **)&buf, "Weapon.manualTarget"))
        return 7;
    manualTarget = (buf[0] == 'F')? false: true;
    return 0;
}
