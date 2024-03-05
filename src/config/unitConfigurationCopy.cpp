// EFRITS
// project:     rts
// created on:  2024-02-25 - 14:10 +0100
// 1st author:  romain.piccoche - romain.picoche
// description: constructor by copy

#include "unit.hh"

ef::ConfUnit::ConfUnit(ef::ConfUnit const &other)
    :ConfObj((ConfObj const &)other),
     cost(other.cost),
     speed(other.speed),
     runningSpeed(other.runningSpeed),
     moveType(other.moveType),
     isFlying(other.isFlying),
     timeToProduce(other.timeToProduce),
     weaponConf(other.weaponConf)
{}
