// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 02/05/2024 10:59:41 ******************************************************
// romain.piccoche <romain.picoche@laika.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "object.hh"
#include "Bpixelarray.hh"

#include <iostream>

void ef::Object::DisplayHealth(ef::Bpixelarray &px,
			       ef::AcuPos caseSize,
			       ef::AcuPos camStart,
			       double zoom,
			       std::vector<ef::ConformPos> path,
			       double progress)
{
  Pos tmp;

  if(progress == -1)
    {
      tmp.x = ((double)pos.x) * caseSize.x;
      tmp.y = ((double)pos.y) * caseSize.y;
    }
  else
    {
      tmp.x = path[0].x * caseSize.x;
      tmp.y = path[0].y * caseSize.y;

      tmp.x += (progress * (path[1].x - path[0].x)) * caseSize.x;
      tmp.y += (progress * (path[1].y - path[0].y)) * caseSize.y;
    }
  tmp.y -= camStart.y * zoom;
  tmp.x -= camStart.x * zoom;

  AcuPos size = caseSize;

  size.x *= objSize.x;

  int tempon = (hp * size.x) / maxhp;

  size.y = (1 + zoom / 2.0) * objSize.y;

  Pos square;

  square.x = tmp.x;
  square.y = tmp.y - ((objSize.y * caseSize.y) / 4);

  Pos max = px.GetSize();
  while(square.y - (tmp.y - ((objSize.y * caseSize.y) / 4)) < size.y)
    {
      if(square.x >= 0 && square.x < max.x && square.y >= 0 && square.y < max.y)
	px.GetSetPixel(square.x, square.y) = (square.x - tmp.x < tempon)? GREEN: RED;
      square.x++;
      if(size.x <= square.x - tmp.x)
	{
	  square.y ++;
	  square.x = tmp.x;
	}
    }
}
