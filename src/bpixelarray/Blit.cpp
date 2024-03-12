#include "Bpixelarray.hh"

void ef::Bpixelarray::Blit(ef::Bpixelarray &other,
                           Pos const &start,
                           AcuPos const &size/*,
                           float const rotate*/)
{
  if(px == NULL || other.px == NULL)
    return;
  Pos end;

  end.x = start.x + other.px->clipable.buffer.width * size.x;
  end.y = start.y + other.px->clipable.buffer.height * size.y;

  Pos cursor;

  cursor.x = start.x;
  cursor.y = start.y;
  while(cursor.x < end.x && cursor.y < end.y)
    {
      double xcoef = (double)(cursor.x - start.x)/(double)(end.x - start.x);
      double ycoef = (double)(cursor.y - start.y)/(double)(end.y - start.y);

      placePixel(cursor, other.pixels
		 [(int)(xcoef * other.px->clipable.buffer.width) +
		  (int)(ycoef * other.px->clipable.buffer.height) * other.px->clipable.buffer.width]);
      if(cursor.x == end.x-1)
	{
	  cursor.x = start.x;
	  cursor.y ++;
	}
      else
	cursor.x ++;
    }
}
