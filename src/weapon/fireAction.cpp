// EFRITS
// project:     rts
// created on:  2024-02-09 - 11:27 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: fireAction implementation

#include "weapon.hh"

std::shared_ptr<ef::Object> ef::Weapon::fireAction(double timePassed)
{
  std::shared_ptr<Object> shoot = nullptr;
  cdr -= timePassed;
  if (cdr < 0)
    cdr = 0;
  if (target.get() != nullptr && cdr == 0)
    {
      //target->takeDmg(nbrAtt, dmg);
      cdr = cdrMax;
      shoot.reset(new Object(shot, target->getPos(), rand(), alegence));
    }
  return shoot;
}

