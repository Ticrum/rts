// EFRITS
// project:     rts
// created on:  2024-02-09 - 12:44 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: Object implementation

#include "object.hh"

ef::Object::Object(ConfObj _conf,
                   Pos _pos,
                   int _objId,
                   int _alegence)
    :
    conf(_conf.conf),
    objId(_objId),
    pos(_pos),
    imgId(_conf.imgId),
    objSize(_conf.objSize),
    hp(_conf.maxhp),
    maxhp(_conf.maxhp),
    armor(_conf.armor),
    rangeOfVision(_conf.rangeOfVision),
    alegence(_alegence)
{
}

