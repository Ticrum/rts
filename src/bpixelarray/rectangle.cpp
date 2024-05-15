// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 23/04/2024 17:21:07 ******************************************************
// romain.piccoche <romain.picoche@laika.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "Bpixelarray.hh"

void ef::Bpixelarray::rectangle(ef::Pos &start,
				ef::AcuPos &size,
				unsigned int &background,
				unsigned int &outline)
{
  AcuPos pos;
  pos.x = start.x;
  pos.y = start.y;

  while(pos.x + px->clipable.buffer.width * pos.y < start.x + size.x + px->clipable.buffer.width * (start.y + size.y))
    {
      if(pos.x >= 0 && pos.y >= 0 && pos.x < px->clipable.buffer.width && pos.y < px->clipable.buffer.height)
	pixels[pos.x + pos.y * px->clipable.buffer.width] = (pos.x == start.x || pos.x == (start.x + size.x) || pos.y == start.y || pos.y == (start.y + size.y - 1)) ? outline : background;
      if(pos.x >= start.x + size.x)
	{
	  pos.x = start.x;
	  pos.y ++;
	}
      else
	pos.x ++;
    }
}
