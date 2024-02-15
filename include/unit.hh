// EFRITS
// project:     rts
// created on:  2024-02-12 - 10:39 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: unit header

#ifndef __UNIT_HH__
#define __UNIT_HH__

#include "weapon.hh"

namespace ef
{
    enum MoveType
    {
        RUN,
        WALK,
        STATIC
    };

    struct ConfUnit : ConfObj
    {
        ConfUnit(std::string file);

        std::string conf;
        int cost;
        double speed;
        double runningSpeed;
        MoveType moveType;
        bool isFlying;
        double timeToProduce;
        std::vector<std::string> weaponConf;
    };

    class Unit : public Object
    {
    public:

        Unit(ConfUnit conf, Pos _pos, int _objId, int _alegence, std::vector<ConfWeapon> & weaponsConf);
        double getSpeed();
        double getRunningSpeed();
        void moveUnit(double timePassed);
        bool fireAllWeapon(double timePassed);
        bool getIsFlying();
        int getActualIndex();
        void changePath(std::vector<Pos> newPath, MoveType type);
        void makeTargeting(std::vector<std::shared_ptr<Object>> others);
        void manualTargeting(std::shared_ptr<Object> target);

    private:
        std::vector<Pos> path;
        int actualIndex;
        double progress;
        double speed;
        double runningSpeed;
        MoveType moveType;
        bool isFlying;
        std::vector<Weapon> weapons;
    };
}; // !ef

#endif // __UNIT_HH__
