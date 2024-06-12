// EFRITS
// project:     rts
// created on:  2024-02-29 - 12:39 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: object2 implementation

#include "object.hh"

ef::Object::Object(ConfObj _conf,
		   std::shared_ptr<ef::Bpixelarray>_img,
		   Pos _pos,
                   int _objId,
                   int _alegence,
                   int actualHp)
  :
  groupButon(0),
  conf(_conf.conf),
  objId(_objId),
  pos(_pos),
  img(_img),
  objSize(_conf.objSize),
  hp(actualHp),
  maxhp(_conf.maxhp),
  armor(_conf.armor),
  rangeOfVision(_conf.rangeOfVision),
  alegence(_alegence),
  nbrDmg(_conf.nbrDmg),
  dmg(_conf.dmg)
{
}

