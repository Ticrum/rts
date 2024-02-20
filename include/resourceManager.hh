// EFRITS
// project:     rts
// created on:  2024-02-20 - 15:44 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: resourceManager header

#ifndef __RESOURCEMANAGER_HH__
#define __RESOURCEMANAGER_HH__

#include "unit.hh"
#include "building.hh"

namespace ef
{
    class ResourceManager
    {
    public:
        ResourceManager();
        ConfUnit getUnit(std::string name);
        ConfBuilding getBuild(std::string name);
        Tech getTech(std::string name);
        std::vector<ConfWeapon> & getWeaponConf();

    private:
        std::vector<ConfUnit> unitConf;
        std::vector<ConfWeapon> weaponConf;
        std::vector<ConfBuilding> buildingConf;
        std::vector<Tech> allTech;
    };
}; // !ef

#endif // __RESOURCEMANAGER_HH__
