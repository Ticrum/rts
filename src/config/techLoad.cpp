#include "building.hh"
#include "Bconf.hh"

int ef::Tech::load(std::string &file)
{
  ef::Bconf conf(file);
    if(conf())
        for(unsigned int i = 0; i < 10 && conf.retry(file); i++);
    if(conf())
        return 1;
    char *buf;
    if(!bunny_configuration_getf_string(conf.Get(), (const char **)&buf, "Tech.name"))
      return 2;
    techName.clear();
    techName.insert(0,buf);
    if(!bunny_configuration_getf_int(conf.Get(), (int *)&isSearched, "Tech.isSearched"))
      return 3;
    if(!bunny_configuration_getf_double(conf.Get(), &timeToSearch, "Tech.timeToSearch"))
      return 4;
    if(!bunny_configuration_getf_int(conf.Get(), &cost, "Tech.cost"))
      return 5;
    return 0;
}
