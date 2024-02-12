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
        Run,
        Walk,
        Static
    };

    struct ConfUnit : ConfObj
    {
        ConfUnit(std::string file);

        std::string conf;
        double speed;
        double runningSpeed;
        MoveType moveType;
        bool isFlying;
        std::vector<std::string> weaponConf;
    };

    class Unit : Object
    {
    public:

        Unit(ConfUnit conf, Pos _pos, int _objId, int _alegence, std::vector<ConfWeapon> & weaponsConf);
        double getSpeed();
        double getRunningSpeed();
        void moveUnit(double timePassed, MoveType movementType);
        bool fireAllWeapon(double timePassed);
        bool getIsFlying();
        int getActualIndex();
        void changePath(std::vector<Pos> newPath);

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
