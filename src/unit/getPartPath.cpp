// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 29/03/2024 12:11:34 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "unit.hh"

#include <iostream>

std::vector<ef::ConformPos> ef::Unit::getPartPath()
{
    std::vector<ConformPos> tempPath;
    if (actualIndex == 0 || 0 == path.size())
      tempPath.push_back(pos.get());
    else
      tempPath.push_back(path[actualIndex - 1].get());
    if(0 == path.size())
      {
	std::cout << "getPartPath pass in path size 0" << std::endl;
	tempPath.push_back(pos.get());
      }
    else
      tempPath.push_back(path[actualIndex].get());
    return tempPath;
}
