// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 23/05/2024 11:13:45 ******************************************************
// romain.piccoche <romain.picoche@laika.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "apiButton.hh"

ef::Labbel &ef::Labbel::operator=(ef::Labbel const &other)
{
  text = other.text;
  font = other.font;
  square.x = other.square.x;
  square.y = other.square.y;
  square.w = other.square.w;
  square.h = other.square.h;
  return *this;
}
