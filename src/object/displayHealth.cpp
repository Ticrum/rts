#include "object.hh"
#include "Bpixelarray.hh"

void ef::Object::DisplayHealth(ef::Bpixelarray &px,
			       ef::Pos caseSize,
			       std::vector<ef::ConformPos> path,
			       double progress)
{
  Pos tmp;

  tmp.x = pos.x * caseSize.x;
  tmp.y = pos.y * caseSize.y;
  if(progress != -1 && (int) path.size() > 1)
    {
      tmp.x += (pos.x + progress * (path[1].x - pos.x)) * caseSize.x;
      tmp.y += (pos.y + progress * (path[1].y - pos.y)) * caseSize.y;
    }

  Pos size = caseSize;

  size.x *= objSize.x;

  int tempon = (hp * size.x) / maxhp;

  size.y = 4 * objSize.y;

  Pos square;

  square.x = tmp.x;
  square.y = tmp.y - 10;

  Pos max = px.GetSize();
  while(square.x-tmp.x < size.x && square.y-tmp.y +10 < size.y)
    {
      if(square.x >= 0 && square.x < max.x && square.y >= 0 && square.y < max.y)
	px.GetSetPixel(square.x, square.y) = (square.x - tmp.x < tempon)? GREEN: RED;
      square.x++;
      if(size.x == square.x - tmp.x)
	{
	  square.y ++;
	  square.x = tmp.x;
	}
    }
}
