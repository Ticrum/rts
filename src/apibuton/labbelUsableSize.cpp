// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 05/06/2024 16:11:18 ******************************************************
// romain.piccoche <romain.picoche@gagarine.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "apiButton.hh"

void ef::Labbel::usableSize(ef::AcuPos size)
{
  square.w = font->GetClip()->buffer.width /127;
  square.h = font->GetClip()->buffer.height;
  if(size.x < square.w * text.size())
    size.x = square.w * text.size() *(int)((size.y >= square.h)?(size.y / square.h) : 1);
  if(size.y < square.h)
    size.y = square.h * (int)(size.x / (square.w * text.size()));
  square.w = size.x / (square.w * text.size());
  square.h = size.y / square.h;
}
