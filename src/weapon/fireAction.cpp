// EFRITS
// project:     rts
// created on:  2024-02-09 - 11:27 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: fireAction implementation

#include "weapon.hh"
#include "unit.hh"

#include <iostream>

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
      if (isTargetBuild)
	shoot.reset(new Object(shot, std::shared_ptr<Bpixelarray>(), target->getPos(), rand(), alegence));
      else
	{
	  std::shared_ptr<Unit> tempUnit = static_pointer_cast<Unit>(target);
	  shoot.reset(new Object(shot, std::shared_ptr<Bpixelarray>(), tempUnit->getActualPos(), rand(), alegence));
	}
      int temphp = target->getHp();
      int damage = shot.dmg - target->getArmor();
      if (damage < 0)
	damage = 0;
      temphp -= damage * shot.nbrDmg;
      if (temphp <= 0)
	target = nullptr;
    }
  if (shoot != nullptr)
    {
      std::cout << "fireAction shoot dmg : " << shoot->getDmg() << " nbrDmg : " << shoot->getNbrDmg() << std::endl;
      std::cout << "fireAction shot dmg : " << shot.dmg << " nbrDmg : " << shot.nbrDmg << std::endl;
      std::cout << "fireAction cdr : " << cdr << std::endl;
    }
  return shoot;
}

