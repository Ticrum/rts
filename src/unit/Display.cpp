#include "unit.hh"
#include "Bpixelarray.hh"

#include <iostream>

void ef::Unit::UnitDisplay(ef::Bpixelarray &px,
                           ef::Pos caseSize,
			   ef::AcuPos camStart)
{
    Pos tmp;

    if (actualIndex == 0)
      {
	tmp.x = ((double)pos.x) * caseSize.x;
	tmp.y = ((double)pos.y) * caseSize.y;
      }
    else
      {
	tmp.x = ((double)path[actualIndex - 1].x) * caseSize.x;
	tmp.y = ((double)path[actualIndex - 1].y) * caseSize.y;
      }
    if(actualIndex + 1 < (int) path.size())
      {
	tmp.x += (progress * ((double)path[actualIndex].x - (double)path[actualIndex - 1].x)) * caseSize.x;
	tmp.y += (progress * ((double)path[actualIndex].y - (double)path[actualIndex - 1].y)) * caseSize.y;
      }
    tmp.y -= camStart.y;
    tmp.x -= camStart.x;
    AcuPos tmpObjSize;

    tmpObjSize.x = objSize.x * caseSize.x;
    tmpObjSize.y = objSize.y * caseSize.y;
    px.Blit(*img, tmp, tmpObjSize, alegence);
}
