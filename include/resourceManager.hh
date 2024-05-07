// EFRITS
// project:     rts
// created on:  2024-02-20 - 15:44 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: resourceManager header

#ifndef __RESOURCEMANAGER_HH__
#define __RESOURCEMANAGER_HH__

#include "building.hh"
#include "Bpixelarray.hh"
#include <map>

namespace ef
{
  class ResourceManager
  {
  public:
    ResourceManager();
    int LoadUnit(bool reset = false);
    ConfUnit getUnit(std::string name);
    int LoadBuild(bool reset = false);
    ConfBuilding getBuild(std::string name);
    int LoadTech(bool reset = false);
    Tech getTech(std::string name);
    int LoadWeapon(bool reset = false);
    std::vector<ConfWeapon> & getWeaponConf();
    int LoadShot(bool reset = false);
    ConfObj getShot(std::string name);
    std::vector<ConfObj> & getShotConf();
    int LoadSprit(bool reset = false);
    std::map<std::string, std::shared_ptr<Bpixelarray>> &getSprit();
    Bpixelarray &getFont();

  private:
    Bpixelarray font;
    std::vector<ConfUnit> unitConf;
    std::vector<ConfWeapon> weaponConf;
    std::vector<ConfBuilding> buildingConf;
    std::vector<Tech> allTech;
    std::vector<ConfObj> shot;
    std::map<std::string, std::shared_ptr<Bpixelarray>> sprites;
  };
}; // !ef

#endif // __RESOURCEMANAGER_HH__
