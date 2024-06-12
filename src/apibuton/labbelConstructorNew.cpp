// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 23/05/2024 11:15:18 ******************************************************
// romain.piccoche <romain.picoche@laika.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "apiButton.hh"

ef::Labbel::Labbel(ef::Pos pos,
		   ef::AcuPos size,
		   std::string msg,
		   std::shared_ptr<ef::Bpixelarray> &styleFont)
  :font(styleFont)
{
  for (unsigned int i = 0; i < msg.size(); ++i)
    text.push_back(msg[i]);
  square.x = pos.x;
  square.y = pos.y;
  /*square.w = size.x;
    square.h = size.y;*/
  usableSize(size);
  /*    if(square.w / square.h != (size.x)/ size.y)
    {
      if(size.x != (int)(font->GetClip()->buffer.width /127))
	if(size.x > (int)(font->GetClip()->buffer.width /127))
	  square.w -= ((int)size.x / msg.size()) % font->GetClip()->buffer.width /127;
	else
	  square.w = msg.size() * (font->GetClip()->buffer.width /127);
      if(size.y != font->GetClip()->buffer.height)
	if(size.y > font->GetClip()->buffer.height)
	  square.h -= ((int)size.y) % font->GetClip()->buffer.height;
	else
	  square.h = font->GetClip()->buffer.height;
    }
  else
    {
      square.w = (size.x) / ( msg.size() * (int)(font->GetClip()->buffer.width /127));
      square.h = size.y / font->GetClip()->buffer.height;
      }*/
}
