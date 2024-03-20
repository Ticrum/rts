#include "object.hh"
#include "Bpixelarray.hh"

void ef::Object::Display(ef::Bpixelarray &px,
                         ef::Pos caseSize)
{
  Pos tmp;

  tmp.x = pos.x * caseSize.x;
  tmp.y = pos.y * caseSize.y;

  AcuPos tmpObjSize;

  tmpObjSize.x = objSize.x* caseSize.x;
  tmpObjSize.y = objSize.y* caseSize.y;
  px.Blit(*img, tmp, tmpObjSize, alegence);
}
