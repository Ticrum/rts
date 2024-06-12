// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 04/03/2024 16:54:30 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "object.hh"
#include "unit.hh"

#include <iostream>

void ef::Object::kaboom(std::vector<std::shared_ptr<Object>> objects,
			bool isBuild)
{
  for (int i = 0; i < (int)objects.size(); i += 1)
    if (isBuild)
      {
	//std::cout << "////KABOOM START////" << std::endl;
	if (objects[i]->getAlegence() != alegence && pos.isInRange(objects[i]->getPos(), objSize.x, objSize.y) != -1)
	  {
	    //std::cout << "\nkaboom tageted obj pos x : " << objects[i]->getPos().x << " y : " << objects[i]->getPos().y << std::endl;
	    //std::cout << "kaboom pojectile pos x : " << pos.x << " y : " << pos.y << std::endl;
	    //std::cout << "kaboom range x : " << objSize.x << " y : " << objSize.y << std::endl;
	    //std::cout << "kaboom conf : " << conf << std::endl;
	    objects[i]->takeDmg(nbrDmg, dmg);
	  }
      }
    else
      {
	std::shared_ptr<Unit> tempUnit = static_pointer_cast<Unit>(objects[i]);
	if (objects[i]->getAlegence() != alegence && pos.isInRange(tempUnit->getActualPos(), objSize.x, objSize.y) != -1)
	  {
	    //std::cout << "kaboom tageted obj pos x : " << tempUnit->getActualPos().x << " y : " << tempUnit->getActualPos().y << std::endl;
	    //std::cout << "kaboom pojectile pos x : " << pos.x << " y : " << pos.y << std::endl;
	    //std::cout << "kaboom range x : " << objSize.x << " y : " << objSize.y << std::endl;
	    objects[i]->takeDmg(nbrDmg, dmg);
	  }
      }
}


