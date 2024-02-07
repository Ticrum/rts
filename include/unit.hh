#ifndef __UNIT_HH__
#define __UNIT_HH__

#include "object.hh"

namespace ef
{
    class Unit : Object
    {
    public:
        enum MoveType
        {
            Run,
            Walk,
            Static
        };

        Unit();
        int getSpeed();
        int getRunningSpeed();
        void moveUnit(double timePassed, MoveType movementType);
        bool fireAllWeapon(double timePassed);
        bool getIsFlying();
        int getActualIndex();
        void changePath(vector<Pos> newPath);

    private:
        vector<Pos> path;
        int actualIndex;
        int speed;
        int runningSpeed;
        MoveType moveType;
        double progress;
        bool isFlying;
        vector<Weapon> weapons;
    };
}; // !ef

#endif // __UNIT_HH__
