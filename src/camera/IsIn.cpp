#include "Bpixelarray.hh"
#include "camera.hh"

bool ef::Camera::IsIn(ef::Pos start,
                      std::shared_ptr<ef::Bpixelarray> &pic)
{
    AcuPos total;
    Pos max = pic->GetSize();
    total.x = pos.x + size.x * zoom;
    total.y = pos.y + size.y * zoom;

    Pos tmp;
    tmp.x = pos.x *zoom;
    tmp.y = pos.y *zoom;
    start.x = start.x + size.x * zoom;
    start.y = start.y + size.y * zoom;
    if(((tmp.x <= start.x || tmp.x <= max.x) &&
        (tmp.y <= start.y || tmp.y <= max.y))
       &&
       (( start.x < total.x || tmp.x < total.x)&&
        ( start.y < total.y || tmp.y < total.y)))
        return true;
    return false;
}
