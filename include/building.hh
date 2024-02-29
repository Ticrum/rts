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
        CONSTRUCT,
        TECH,
        ENERGY,
        MONEY
    };

    struct ConfBuilding : ConfObj
    {
        ConfBuilding(std::string file);

        int cost;
        double timeToProduce;
        BuildingType type;
        bool canBeTarget;
        int energyCost;
        int energyProduction;
        int moneyProduction;
        std::vector<std::string> weaponConf;
    };

    class Building : public Object
    {
    public:
        Building(ConfBuilding conf, Pos _pos, int _objId, int _alegence, std::vector<ConfWeapon> & weaponsConf);
        Building(ConfBuilding conf, Pos _pos, int _objId, int _alegence, std::vector<ConfWeapon> & weaponsConf, int actualHp, std::vector<double> cdr);
        bool fireAllWeapon(double timePassed);
        void changeTarget(std::vector<std::shared_ptr<Object>> targets);
        BuildingType getType();
        bool getCanBeTarget();
        int getEnergyCost();
        bool getIsActive();
        void setIsActive(bool newState);
        int getEnergyProduction();
        int getMoneyProduction();
        TargetReturn makeTargeting(std::vector<std::shared_ptr<Object>> others);
        void manualTargeting(std::shared_ptr<Object> target);
        std::vector<double> getWeaponsCd();

    protected:
        BuildingType type;
        bool canBeTarget;
        int energyCost;
        int energyProduction;
        int moneyProduction;
        bool isActive;
        std::vector<Weapon> weapons;
    };

    class ProdBuilding : public Building
    {
    public:
        ProdBuilding(ConfBuilding conf, Pos _pos, int _objId, int _alegence, std::vector<ConfWeapon> & weaponsConf);
        ProdBuilding(ConfBuilding conf, Pos _pos, int _objId, int _alegence, std::vector<ConfWeapon> & weaponsConf, int actualHp, std::vector<double> cdr);
        std::shared_ptr<Unit> produceUnit(double timePassed,
                                          std::vector<ConfWeapon> & weaponsConf);
        void addUnitToProd(ConfUnit newUnit);
        bool getOnHold();
        void setOnHold(bool newState);

    private:
        std::vector<ConfUnit> unitProd;
        double timeLeft;
        bool onHold;
    };

    class ConstructBuilding : public Building
    {
    public:
        ConstructBuilding(ConfBuilding conf, Pos _pos, int _objId, int _alegence, std::vector<ConfWeapon> & weaponsConf);
        ConstructBuilding(ConfBuilding conf, Pos _pos, int _objId, int _alegence, std::vector<ConfWeapon> & weaponsConf, int actualHp, std::vector<double> cdr);
        std::shared_ptr<Building> produceBuilding(double timePassed,
                                                  std::vector<ConfWeapon> & weaponsConf);
        void addBuildingToProd(ConfBuilding newBuilding);
        bool getOnHold();
        void setOnHold(bool newState);

    private:
        std::vector<ConfBuilding> buildingProd;
        double timeLeft;
        bool onHold;
    };

    struct Tech
    {
        std::string techName;
        bool isSearched;
        double timeToSearch;
        int cost;
    };

    class TechBuilding : public Building
    {
    public:
        TechBuilding(ConfBuilding conf, Pos _pos, int _objId, int _alegence, std::vector<ConfWeapon> & weaponsConf);
        TechBuilding(ConfBuilding conf, Pos _pos, int _objId, int _alegence, std::vector<ConfWeapon> & weaponsConf, int actualHp, std::vector<double> cdr);
        std::shared_ptr<Tech> searchTech(double timePassed);
        void addSearchToList(Tech newSearch);
        bool getOnHold();
        void setOnHold(bool newState);

    private:
        std::vector<Tech> techResearch;
        double timeLeft;
        bool onHold;
    };
}; // !ef

#endif // __BUILDING_HH__
