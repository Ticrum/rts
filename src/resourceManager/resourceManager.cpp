// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 05/03/2024 17:42:51 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "resourceManager.hh"

ef::ResourceManager::ResourceManager()
{
  buildingConf.emplace_back("resours/building/conf/LATHOURES.dabsic");
  buildingConf.emplace_back("resours/building/conf/MainBuild.dab");
  unitConf.emplace_back("resours/unit/conf/missingno.dabsic");
  weaponConf.emplace_back("resours/weapon/conf/LEsTIK.dabsic");
  weaponConf.emplace_back("resours/building/conf/miniGun.dabsic");
}

