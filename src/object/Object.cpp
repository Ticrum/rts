// EFRITS
// project:     rts
// created on:  2024-02-09 - 12:44 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: Object implementation

#include "object.hh"

ef::Object::Object(ConfObj conf,
                   Pos _pos,
                   int _objId,
                   int _alegence)
    :
    objId(_objId),
    pos(_pos),
    imgId(conf.imgId),
    objSize(conf.objSize),
    hp(conf.maxhp),
    maxhp(conf.maxhp),
    armor(conf.armor),
    rangeOfVision(conf.rangeOfVision),
    alegence(_alegence)
{
}

