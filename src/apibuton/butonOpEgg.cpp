// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 27/03/2024 18:33:14 ******************************************************
// romain.piccoche <romain.picoche@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "apiButton.hh"

ef::Buton &ef::Buton::operator=(Buton const& other)
{
  group = other.group;
  id = other.id;
  square.x = other.square.x;
  square.y = other.square.y;
  square.h = other.square.h;
  square.w = other.square.w;
  outside.full = other.outside.full;
  background.full = other.background.full;
  sprit = other.sprit;
  command = other.command;
  action = other.action;
  return *this;
}
