// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 07/06/2024 11:53:39 ******************************************************
// romain.piccoche <romain.picoche@terechkova.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "object.hh"
#include "apiButton.hh"

void ef::Object::updateApiButonInfo(ef::ButonManager &manager,
				    std::map<std::string, std::shared_ptr<Bpixelarray>> &sprits)
{
  manager.updateLabbel(labbelId[0], std::to_string(hp) + " / " + std::to_string(maxhp));
}
