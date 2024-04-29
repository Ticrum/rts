// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 27/04/2024 14:38:50 ******************************************************
// romain.piccoche <romain.picoche@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "building.hh"

std::string ef::extract(unsigned int &start,
			std::string &source,
			char stop)
{
  std::string output("");

  while(source[start] != stop && start < source.size())
    {
      output.push_back(source[start]);
      start ++;
    }
  start ++;
  return output;
}
