#include "unit.hh"

ef::ConfUnit &ef::ConfUnit::operator=(ConfUnit const&other)
{
    cost = other.cost;
    speed = other.speed;
    runningSpeed= other.runningSpeed;
    moveType= other.moveType;
    isFlying= other.isFlying;
    timeToProduce= other.timeToProduce;
    weaponConf= other.weaponConf;
    ConfObj::operator=(other);
    return *this;
}
