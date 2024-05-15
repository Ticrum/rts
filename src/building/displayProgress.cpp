// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 13/05/2024 11:17:34 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "building.hh"

#include <iostream>

void ef::Building::displayProgress(ef::Bpixelarray &px,
				   ef::AcuPos caseSize,
				   ef::AcuPos camStart,
				   double zoom,
				   std::shared_ptr<Building> self)
{
  //std::cout << "displayProgress type : " << type << std::endl;
  if (type == PRODUCTION)
    {
      std::shared_ptr<ProdBuilding> prod = std::static_pointer_cast<ProdBuilding>(self);
      prod->displayProgress(px, caseSize, camStart, zoom);
    }
  else if (type == CONSTRUCT)
    {
      std::shared_ptr<ConstructBuilding> prod = std::static_pointer_cast<ConstructBuilding>(self);
      prod->displayProgress(px, caseSize, camStart, zoom);
    }
}

