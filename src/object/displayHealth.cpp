#include "object.hh"
#include "Bpixelarray.hh"

void ef::Object::DisplayHealth(ef::Bpixelarray &px,
			       ef::Pos caseSize,
			       ef::AcuPos camStart,
			       std::vector<ef::ConformPos> path,
			       double progress)
{
  Pos tmp;

  tmp.x = ((double)pos.x) * caseSize.x;
  tmp.y = ((double)pos.y) * caseSize.y;
  if(progress != -1 && (int) path.size() > 1)
    {
      tmp.x += (progress * (path[1].x - pos.x)) * caseSize.x;
      tmp.y += (progress * (path[1].y - pos.y)) * caseSize.y;
    }
  tmp.y -= camStart.y;
  tmp.x -= camStart.x;

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
