// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 06/06/2024 13:32:05 ******************************************************
// romain.piccoche <romain.picoche@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "clientPlayerInfo.hh"
#include "resourceManager.hh"

void ef::ClientPlayerInfo::updateSelectedInfo()
{
  if(selectedBuilding.size() > 0)
    switch(selectedBuilding[0]->getType())
      {
      case CONSTRUCT:
	std::static_pointer_cast<ef::ConstructBuilding>(selectedBuilding[0])->updateApiButonInfo(man, res.getSprit());
	break;
      case PRODUCTION:
	std::static_pointer_cast<ef::ProdBuilding>(selectedBuilding[0])->updateApiButonInfo(man, res.getSprit());
	break;
      default:
	selectedBuilding[0]->updateApiButonInfo(man, res.getSprit());
      }
}
