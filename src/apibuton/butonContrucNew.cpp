// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 27/03/2024 18:20:56 ******************************************************
// romain.piccoche <romain.picoche@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "apiButton.hh"

ef::Buton::Buton(unsigned int _group,
		 unsigned int _id,
		 bool _print,
		 t_bunny_accurate_area _square,
		 unsigned int _outside,
		 unsigned int _background,
		 std::shared_ptr<ef::Bpixelarray> _px,
		 std::string _action,
		 std::function<void(std::string)> func)
  :group(_group),
   id(_id),
   print(_print),
   outside(_outside),
   background(_background),
   sprit(_px),
   command(_action),
   action(func)
{
  square.x = _square.x;
  square.y = _square.y;
  square.h = _square.h;
  square.w = _square.w;
}
