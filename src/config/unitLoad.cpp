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
  if(tmp > 0)
    return tmp;
  if(!bunny_configuration_getf_int(conf.Get(), &cost, "Unit.cost"))
    return 12;
  if(!bunny_configuration_getf_double(conf.Get(), &speed, "Unit.speed"))
    return 13;
  if(!bunny_configuration_getf_double(conf.Get(), &runningSpeed, "Unit.runningSpeed"))
    return 14;
  if(!bunny_configuration_getf_int(conf.Get(), (int *)&moveType, "Unit.moveType"))
    return 15;
  if(moveType < 0 || moveType > 2)
    return 19;
  if(!bunny_configuration_getf_int(conf.Get(), (int *)&isFlying, "Unit.isFlying"))
    return 16;
  if(!bunny_configuration_getf_double(conf.Get(), &timeToProduce, "Unit.timeToProduce"))
    return 17;
  char *buf;
  int size;
  if(!bunny_configuration_getf_int(conf.Get(), &size, "Unit.weaponConf.size"))
    return 18;
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
