// EFRITS
// project:     rts
// created on:  2024-02-12 - 11:19 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: building header

#ifndef __BUILDING_HH__
#define __BUILDING_HH__

#include "unit.hh"

namespace ef
{
    enum BuildingType
    {
        PRODUCTION,
        TECH,
        ENERGY,
        MONEY
    };

    struct ConfBuilding : ConfObj
    {
        ConfBuilding(std::string file);

        std::string conf;
        BuildingType type;
        bool canBeTarget;
        int energyCost;
        int moneyProduction;
        std::vector<std::string> weaponConf;
    };

    class Building : Object
    {
    public:
        Building(ConfBuilding conf, Pos _pos, int _objId, int _alegence, std::vector<ConfWeapon> & weaponsConf);
        bool fireAllWeapon(double timePassed);
        BuildingType getType();
        bool getCanBeTarget();
        int getEnergyCost();
        bool getIsActive();
        void setIsActive(bool newState);

    protected:
        BuildingType type;
        bool canBeTarget;
        int energyCost;
        int moneyProduction;
        bool isActive;
        std::vector<Weapon> weapons;
    };

    class EnergyBuilding : Building
    {
    public:
        EnergyBuilding();
        int getEnergyProduction();

    private:
        int energyProduction;
    };

    class ProdBuilding : Building
    {
    public:
        ProdBuilding();
        std::shared_ptr<Unit> produceUnit(double timePassed);
        void addUnitToProd(std::string newUnit);
        bool getOnHold();
        void setOnHold();

    private:
        std::vector<std::string> unitProd;
        double timeLeft;
        bool onHold;
    };

    struct Tech
    {
        std::string techName;
        bool isSearched;
    };

    class TechBuilding : Building
    {
    public:
        TechBuilding();
        std::shared_ptr<Tech> searchTech(double timePassed);
        void addSearchToList(std::string newSearch);
        bool getOnHold();
        void setOnHold();

    private:
        std::vector<std::string> techResearch;
        double timeLeft;
        bool onHold;
    };
}; // !ef

#endif // __BUILDING_HH__
