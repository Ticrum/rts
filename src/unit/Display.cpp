#include "unit.hh"
#include "Bpixelarray.hh"

#include <iostream>

void ef::Unit::UnitDisplay(ef::Bpixelarray &px,
                           ef::AcuPos caseSize,
			   ef::AcuPos camStart,
			   double zoom)
{
    Pos tmp;

    if (actualIndex == 0 || path.size() == 0)
      {
	tmp.x = ((double)pos.x) * caseSize.x;
	tmp.y = ((double)pos.y) * caseSize.y;
      }
    else
      {
	tmp.x = ((double)path[actualIndex - 1].x) * caseSize.x;
	tmp.y = ((double)path[actualIndex - 1].y) * caseSize.y;
      }
    if(actualIndex < (int) path.size())
      {
	if (actualIndex == 0)
	  {
	    tmp.x += (progress * ((double)path[actualIndex].x - (double)pos.x)) * caseSize.x;
	    tmp.y += (progress * ((double)path[actualIndex].y - (double)pos.y)) * caseSize.y;
	  }
	else
	  {
	    tmp.x += (progress * ((double)path[actualIndex].x - (double)path[actualIndex - 1].x)) * caseSize.x;
	    tmp.y += (progress * ((double)path[actualIndex].y - (double)path[actualIndex - 1].y)) * caseSize.y;
	  }
      }
    tmp.y -= camStart.y * zoom;
    tmp.x -= camStart.x * zoom;
    AcuPos tmpObjSize;

    tmpObjSize.x = objSize.x * caseSize.x;
    tmpObjSize.y = objSize.y * caseSize.y;
    px.Blit(*img, tmp, tmpObjSize, alegence);
}
