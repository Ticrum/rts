#include "unit.hh"
#include "Bpixelarray.hh"

#include <iostream>

void ef::Unit::UnitDisplay(ef::Bpixelarray &px,
                           ef::Pos caseSize)
{
    Pos tmp;

    if (actualIndex == 0)
      {
	tmp.x = pos.x * caseSize.x;
	tmp.y = pos.y * caseSize.y;
      }
    else
      {
	tmp.x = path[actualIndex - 1].x * caseSize.x;
	tmp.y = path[actualIndex - 1].y * caseSize.y;
      }
    if(actualIndex + 1 < (int) path.size())
        {
	  std::cout << "JE PASSE DANS UNITDISPLAY!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
            tmp.x += (progress * (path[actualIndex].x - pos.x)) * caseSize.x;
            tmp.y += (progress * (path[actualIndex].y - pos.y)) * caseSize.y;
        }

    AcuPos tmpObjSize;

    tmpObjSize.x = objSize.x * caseSize.x;
    tmpObjSize.y = objSize.y * caseSize.y;
    px.Blit(*img, tmp, tmpObjSize, alegence);

    Pos size = caseSize;

    size.x *= objSize.x;
    size.y = 4 * objSize.y;

    Pos square;

    square.x = tmp.x;
    square.y = tmp.y - 20;

    int tempon = (hp * size.x) / maxhp;
    while(square.x-tmp.x < size.x && square.y-tmp.y +20 < size.y)
        {
	  px.placePixel(square, (square.x - tmp.x < tempon)? GREEN: RED);
	  square.x++;
	  if(size.x-1 == square.x - tmp.x)
	    {
	      square.y ++;
	      square.x = tmp.x;
	    }
        }
}
