#ifndef __BUILDING_HH__
#define __BUILDING_HH__

#include "object.hh"

namespace ef
{
    class Building : Object
    {
    public:
        enum buildingType
            {
                PRODUCTION,
                TECH,
                ENERGY,
                MONEY
            };

        Building();
        bool fireAllWeapon(double timePassed);
        buildingType getType();
        bool getCanBeTarget();
        int getEnergyCost();
        bool getIsActive();
        void setIsActive(bool newState);

    protected:
        buildingType type;
        bool canBeTarget;
        int energyCost;
        int moneyProduction;
        bool isActive;
        vector<Weapon> weapons;
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
        shared_ptr<Unit> produceUnit(double timePassed);
        void addUnitToProd(string newUnit);
        bool getOnHold();
        void setOnHold();

    private:
        vector<string> unitProd;
        double timeLeft;
        bool onHold;
    };

    class TechBuilding : Building
    {
    public:
        TechBuilding();
        shared_ptr<Tech> searchTech(double timePassed);
        void addSearchToList(string newSearch);
        bool getOnHold();
        void setOnHold();

    private:
        vector<string> techResearch;
        double timeLeft;
        bool onHold;
    };
}; // !ef

#endif // __BUILDING_HH__
