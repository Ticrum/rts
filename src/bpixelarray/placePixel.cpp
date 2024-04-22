#include "Bpixelarray.hh"

#include <iostream>

void ef::Bpixelarray::placePixel(Pos &pos,
                                 unsigned int colo)
{
  if(pos.x >= 0 && pos.x < px->clipable.buffer.width && pos.y >= 0 && pos.y < px->clipable.buffer.height)
    {
      t_bunny_color last;
      t_bunny_color color;
      color.full = colo;
      last.full = pixels[pos.x + px->clipable.buffer.width * pos.y];
      if(color.argb[ALPHA_CMP] !=255)
	{
	  double ratio = color.argb[ALPHA_CMP] / 255.0;
	  //std::cout << "placePixel ratio" << ratio << std::endl;
	  color.argb[RED_CMP] = last.argb[RED_CMP] +ratio * (color.argb[RED_CMP]- last.argb[RED_CMP]);
	  color.argb[GREEN_CMP] = last.argb[GREEN_CMP] +ratio * (color.argb[GREEN_CMP]- last.argb[GREEN_CMP]);
	  color.argb[BLUE_CMP] = last.argb[BLUE_CMP] +ratio * (color.argb[BLUE_CMP]- last.argb[BLUE_CMP]);
	  pixels[pos.x + px->clipable.buffer.width * pos.y] = color.full;
	}
      else
	pixels[pos.x + px->clipable.buffer.width * pos.y] = colo;
    }
}
