#include "Bpixelarray.hh"
#include "camera.hh"

bool ef::Camera::IsIn(ef::Pos &start,
                      ef::Bpixelarray &pic)
{
    AcuPos total;
    Pos max = pic.GetSize();
    total.x = pos.x + size.x * zoom;
    total.y = pos.y + size.y * zoom;

    if(((pos.x <= start.x || pos.x <= max.x) &&
        (pos.y <= start.y || pos.y <= max.y))
       &&
       (( start.x < total.x || pos.x < total.x)&&
        ( start.y < total.y || pos.y < total.y)))
        return true;
    return false;
}
