#include "object.hh"
#include "Bpixelarray.hh"

void ef::Object::Display(ef::Bpixelarray &px,
                         ef::AcuPos caseSize,
			 ef::AcuPos camStart,
			 double zoom)
{
  Pos tmp;

  tmp.x = ((double)pos.x) * caseSize.x - camStart.x * zoom;
  tmp.y = ((double)pos.y) * caseSize.y - camStart.y * zoom;

  AcuPos tmpObjSize;

  tmpObjSize.x = objSize.x* caseSize.x;
  tmpObjSize.y = objSize.y* caseSize.y;
  px.Blit(*img, tmp, tmpObjSize, alegence);
}
