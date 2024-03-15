#include "object.hh"
#include "Bpixelarray.hh"
#include <iostream>
void ef::Object::Display(ef::Bpixelarray &px,
                         ef::Pos caseSize)
{
    Pos tmp;

    tmp.x = pos.x * caseSize.x;
    tmp.y = pos.y * caseSize.y;

    AcuPos tmpObjSize;

    tmpObjSize.x = objSize.x* caseSize.x;
    tmpObjSize.y = objSize.y* caseSize.y;
    px.Blit(*img, tmp, tmpObjSize,alegence);

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
	  if(size.x == square.x - tmp.x)
	    {
	      square.y ++;
	      square.x = tmp.x;
	    }
        }
}
