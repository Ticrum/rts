#include "object.hh"
#include "Bpixelarray.hh"
#include <iostream>

void ef::Object::DisplayHealth(ef::Bpixelarray &px,
			       ef::Pos caseSize,
			       std::vector<ef::ConformPos> path,
			       double progress)
{
  std::cout<< "in\n";
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

  std::cout << "start  " << tmp.x << " | " <<tmp.y<<
    "\nsize   " << size.x << " | " << size.y<<
    "\nsquare " << square.x << " | "<< square.y<< "\n";
  Pos max = px.GetSize();
  while(square.x-tmp.x < size.x && square.y-tmp.y +10 < size.y)
    {
      std::cout << square.x-tmp.x<< " / "<< size.x << "|" << square.y-tmp.y +20 << " / " << size.y <<"\n";
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
