#include "Bpixelarray.hh"
#include <iostream>
#include <map>
void ef::Bpixelarray::Blit(ef::Bpixelarray &other,
                           Pos const &start,
                           AcuPos const &size,
			   int alegence/*,
                           float const rotate*/)
{
  if(px == NULL || other.px == NULL)
    return;
  std::map<int, bool> gate;
  t_bunny_color colo;
  colo.full = (alegence + 24) * (alegence + 42) * 10000 + (alegence + 69) * (alegence + 34);
  colo.argb[RED_CMP] += colo.argb[ALPHA_CMP] * 1.0/3.0;
  colo.argb[GREEN_CMP] += colo.argb[ALPHA_CMP] * 1.0/3.0;
  colo.argb[BLUE_CMP] += colo.argb[ALPHA_CMP] * 1.0/3.0;
  Pos end;

  end.x = start.x + size.x;
  end.y = start.y + size.y;

  Pos cursor;

  cursor.x = start.x;
  cursor.y = start.y;
  double xcoef;
  double ycoef;
  unsigned int color;
  while(cursor.x < end.x && cursor.y < end.y)
    {
      xcoef = (double)(cursor.x - start.x)/(double)(end.x - start.x);
      ycoef = (double)(cursor.y - start.y)/(double)(end.y - start.y);
      color = other.pixels[(int)(xcoef * other.px->clipable.buffer.width) +
	 (int)(ycoef * other.px->clipable.buffer.height) * other.px->clipable.buffer.width];
      if(gate.count(color) == 0)
	{
	  std::cout<< "color " << color << "\n" << cursor.x << "| "<< cursor.y << "\n";
	  gate[color] = true;
	}
      if(color == 4289069221)
	placePixel(cursor, colo.full);
      else
	if(color != 4294902015)
	  placePixel(cursor, color);
      if(cursor.x == end.x-1)
	{
	  cursor.x = start.x;
	  cursor.y ++;
	}
      else
	cursor.x ++;
    }
}
