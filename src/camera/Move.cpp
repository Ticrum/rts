#include "camera.hh"

void ef::Camera::Move(AcuPos move)
{
    pos.x += move.x;
    pos.y += move.y;
    if (pos.x < -(size.x - 20))
      pos.x = -(size.x - 20);
    else if (pos.x > size.x - 20)
      pos.x = size.x - 20;
    if (pos.y < -(size.y - 20))
      pos.y = -(size.y - 20);
    else if (pos.y > size.y - 20)
      pos.y = size.y - 20;
}
