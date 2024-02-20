#include "object.hh"
#include "Bpixelarray.hh"

void ef::Object::Display(ef::Bpixelarray &px,
                         std::vector<ef::Bpixelarray> &rsrc,
                         ef::Pos caseSize)
{
    Pos tmp;

    tmp.x = pos.x * caseSize.x;
    tmp.y = pos.y * caseSize.y;

    AcuPos tmpObjSize;

    tmpObjSize.x = objSize.x;
    tmpObjSize.y = objSize.y;
    px.Blit(rsrc[imgId], tmp, tmpObjSize);

    Pos size = px.GetSize();

    size.x /= caseSize.x;
    size.y = 10;

    Pos square;

    square.x = 0;
    square.y = 0;

    int tempon = (hp * size.x) / maxhp;
    while(square.x <= size.x && square.y < size.y)
        {
            px.GetSetPixel(square.x + tmp.x, tmp.y - square.y - 2) = (square.x < tempon)? GREEN: RED;
            if(size.x == square.x)
                {
                    square.y ++;
                    square.x = 0;
                }
            else
                square.x++;
        }
}
