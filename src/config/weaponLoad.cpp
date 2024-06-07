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
  const char *buf;
  if(!bunny_configuration_getf_string(conff.Get(), &buf, "Weapon.name"))
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
  if(!bunny_configuration_getf_bool(conff.Get(), &manualTarget , "Weapon.manualTarget"))
    return 7;
  if(!bunny_configuration_getf_bool(conff.Get(), &canTargetFly , "Weapon.canTargetFly"))
    return 9;
  if(!bunny_configuration_getf_string(conff.Get(), &buf, "Weapon.shot"))
    return 8;
  ShotConf.clear();
  ShotConf.insert(0, buf);
  return 0;
}
