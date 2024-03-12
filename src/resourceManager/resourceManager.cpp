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
  int compt = 0;

  while (LoadUnit(false) >= 0 && compt < 5)
    compt += 1;
  compt = 0;
  while (LoadBuild(false) >= 0 && compt < 5)
    compt += 1;
  compt = 0;
  while (LoadTech(false) >= 0 && compt < 5)
    compt += 1;
  compt = 0;
  while (LoadWeapon(false) >= 0 && compt < 5)
    compt += 1;
  compt = 0;
  while (LoadShot(false) >= 0 && compt < 5)
    compt += 1;
  compt = 0;
  while (LoadSprit(false) >= 0 && compt < 5)
    compt += 1;
}

