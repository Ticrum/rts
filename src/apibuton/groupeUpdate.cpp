// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 27/03/2024 17:29:33 ******************************************************
// romain.piccoche <romain.picoche@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "apiButton.hh"

unsigned int ef::Groupe::update(t_bunny_accurate_area square)
{
  if(square.x < min.x)
    min.x = square.x;
  if(square.y < min.y)
    min.y = square.y;
  if(square.x + square.w > max.x)
    max.x = square.x + square.w;
  if(square.y + square.h > max.y)
    max.y = square.y + square.h;
  return Id ++;
}
