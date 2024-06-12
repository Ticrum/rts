// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 12/06/2024 11:58:01 ******************************************************
// romain.piccoche <romain.picoche@terechkova.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
#include "building.hh"
#include "apiButton.hh"
void ef::ConstructBuilding::displayInfo(ef::Pos size,
				   ButonManager &manager,
				   std::function<void(std::string)> func,
				   std::map<std::string, std::shared_ptr<Bpixelarray>> &sprits)
{
  ef::Building::displayInfo(size, manager, sprits);
  ef::Pos start;
  start.x = 0.3 * size.x;
  start.y = 0.7 * size.y;
  size.x = 0.7 * size.x;
  size.y = 0.3 * size.y;
  t_bunny_accurate_area square;
  square.x = start.x + 9.0 / 30.0 * size.x;
  square.w = size.y / 4.0;
  square.y = start.y + size.y / 2.0 - square.w /2.0;
  square.h = square.w;
  //std::cout<<"x: " << square.x << "\ny: "<< square.y<< "\nw: " << square.w << "\nh: " << square.h << "\n";
  idQu[0] = manager.add(groupButon, true, square, RED, RED, (buildingProd.size() > 0)?sprits[buildingProd[0]. img]:sprits["waitToProd0.png"], "TXT need to replace0", func, false).y;
  square.w /= 2.0;
  square.x += square.h + square.w/4.0;
  square.y += square.w;
  square.h = square.w;
  for(int i = 1; i < 5; ++i)
      {
	idQu[i] = manager.add(groupButon, true, square, RED, RED, ((i >= buildingProd.size())? sprits["waitToProd" + std::to_string(i) + ".png"]: sprits[buildingProd[i]. img]), "TXT need to replace" + std::to_string(i), func, false).y;
	square.x += square.w + square.w/4.0;
      }
    /*std::cout << groupButon << " : " << idQu[0] << ", " << idQu[1] << ", " << idQu[2] << ", " << idQu[3] << ", " << idQu[4] << std::endl;
    manager.printTerminal();*/
}
