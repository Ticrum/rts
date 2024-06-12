// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 23/05/2024 18:23:15 ******************************************************
// romain.piccoche <romain.picoche@laika.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "apiButton.hh"

unsigned int ef::ButonManager::add (ef::Pos pos,
				    ef::AcuPos size,
				    std::string msg,
				    std::shared_ptr<ef::Bpixelarray> &styleFont)
{
  int max = 0;
  for(unsigned int i = 0; i < groupLabIds.size(); ++i)
    if(max <= groupLabIds[i])
      max = groupLabIds[i]+1;
  groupLab[max] = ef::Labbel(pos, size, msg, styleFont);
  groupLabIds.push_back(max);
  return max;
}
