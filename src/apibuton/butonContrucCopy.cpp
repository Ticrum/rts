// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 27/03/2024 13:11:11 ******************************************************
// romain.piccoche <romain.picoche@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "apiButton.hh"

ef::Buton::Buton(Buton const& other)
  :group(other.group),
   id(other.id),
   outside(other.outside),
   background(other.background),
   sprit(other.sprit),
   command(other.command),
   action(other.action)
{
  square.x = other.square.x;
  square.y = other.square.y;
  square.h = other.square.h;
  square.w = other.square.w;
}
