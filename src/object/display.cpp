#include "object.hh"
#include "Bpixelarray.hh"

void ef::Object::Display(ef::Bpixelarray &px,
                         ef::Pos caseSize,
			 ef::AcuPos camStart)
{
  Pos tmp;

  tmp.x = ((double)pos.x) * caseSize.x - camStart.x;
  tmp.y = ((double)pos.y) * caseSize.y - camStart.y;

  AcuPos tmpObjSize;

  tmpObjSize.x = objSize.x* caseSize.x;
  tmpObjSize.y = objSize.y* caseSize.y;
  px.Blit(*img, tmp, tmpObjSize, alegence);
}
