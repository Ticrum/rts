// EFRITS
// project:     rts
// created on:  2024-02-20 - 15:44 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: resourceManager header

#ifndef __RESOURCEMANAGER_HH__
#define __RESOURCEMANAGER_HH__

#include "building.hh"

namespace ef
{
  class ResourceManager
  {
  public:
    ConfUnit getUnit(std::string name);
    ConfBuilding getBuild(std::string name);
    Tech getTech(std::string name);
    std::vector<ConfWeapon> & getWeaponConf();
    ConfObj getShot(std::string name);
    std::vector<std::shared_ptr<Bpixelarray>> getSprit();
  private:
    std::vector<ConfUnit> unitConf;
    std::vector<ConfWeapon> weaponConf;
    std::vector<ConfBuilding> buildingConf;
    std::vector<Tech> allTech;
    std::vector<ConfObj> shot;
    std::vector<std::shared_ptr<Bpixelarray>> sprites;
  };
}; // !ef

#endif // __RESOURCEMANAGER_HH__
