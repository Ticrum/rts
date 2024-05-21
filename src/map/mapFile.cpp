// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 15/05/2024 16:38:42 ******************************************************
// romain.piccoche <romain.picoche@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "map.hh"
#include "Bconf.hh"
#include <iostream>

ef::Map::Map(std::string &file)
{
  Bconf conf(std::string("resours/maps/") + file);
  bool gate = true;
  if(conf())
    for(unsigned int i = 0; i < 10 && conf.retry(std::string("resours/maps/") +file); i++);
  if(!conf())
    if(bunny_configuration_getf_int(conf.Get(), &mapSize.x, "Map.Size.x"))
      if(bunny_configuration_getf_int(conf.Get(), &mapSize.y, "Map.Size.y"))
	{
	  map.resize(mapSize.x * mapSize.y);
	  for(unsigned int i = 0; gate && i < map.size(); ++i)
	    if(!bunny_configuration_getf_int(conf.Get(), (int *)&map[i], "Map.map[%d]", i))
	      {
		std::cout<<"fail to get the "<< i%mapSize.x << ", " << (int)(i/mapSize.x) << "case in map in ressours/maps/" << file<< std::endl;
		gate = false;
	      }
	}
      else
	{
	  std::cout<< "fail to load Map.Size.x for ressours/maps/" << file << std::endl;
	  gate = false;
	}
    else
      {
	std::cout<< "fail to load Map.Size.x for ressours/maps/" << file<< std::endl;
	gate = false;
      }
  else
    {
      std::cout<< "fail to open conf for ressours/maps/" << file<< std::endl;
      gate = false;
    }
  if(!gate)
    {
      std::cout<< "yep it's fail" <<std::endl;
      if(map.size() < 4096)
	map.resize(4096);
      mapSize.x = 64;
      mapSize.y = 64;
      for(unsigned int i = 0; i < map.size(); ++i)
	map[i]=0;
    }
}
