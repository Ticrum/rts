// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 12/06/2024 12:19:32 ******************************************************
// romain.piccoche <romain.picoche@terechkova.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "building.hh"
#include "apiButton.hh"
#include <iostream>

void ef::ConstructBuilding::updateApiButonInfo(ef::ButonManager &manager,
					       std::map<std::string, std::shared_ptr<ef::Bpixelarray>> &sprits)
{
  if(needToUpdate)
    {
      std::cout << "PRODBUILDING IN" << std::endl;
      for(unsigned char i = 0; i < 5; i++)
      {
	std::cout << "Boucle" << std::endl;
	manager.changePx(groupButon, idQu[i], ((i >= buildingProd.size())? sprits["waitToProd" + std::to_string(i) + ".png"]: sprits[buildingProd[i]. img]));
	std::cout << ((i >= buildingProd.size())? "waitToProd": "IIIMMMGGG!") << " = " <<(((i >= buildingProd.size())? sprits["waitToProd" + std::to_string(i) + ".png"]: sprits[buildingProd[i]. img])->GetClip() == NULL)<< std::endl;
      }
      ef::Building::updateApiButonInfo(manager, sprits);
    needToUpdate = false;
    std::cout << "\n" << std::endl;
    }
}
