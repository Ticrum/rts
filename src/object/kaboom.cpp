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

void ef::Object::kaboom(std::vector<std::shared_ptr<Object>> objects)
{
  for (int i = 0; i < (int)objects.size(); i += 1)
    if (objects[i]->getAlegence() != alegence && pos.isInRange(objects[i]->getPos(), objSize.x, objSize.y))
      objects[i]->takeDmg(nbrDmg, dmg);
}


