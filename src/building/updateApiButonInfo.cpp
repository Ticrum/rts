// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 07/06/2024 12:10:05 ******************************************************
// romain.piccoche <romain.picoche@terechkova.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "building.hh"

void ef::Building::updateApiButonInfo(ef::ButonManager &manager,
				      std::map<std::string, std::shared_ptr<Bpixelarray>> &sprits)
{
  ef::Object::updateApiButonInfo(manager, sprits);
}
