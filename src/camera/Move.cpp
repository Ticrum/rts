#include "camera.hh"

void ef::Camera::Move(AcuPos move)
{
    pos.x += move.x;
    pos.y += move.y;
    if (pos.x < -size.x)
      pos.x = -size.x;
    else if (pos.x > size.x)
      pos.x = size.x;
    if (pos.y < -size.y)
      pos.y = -size.y;
    else if (pos.y > size.y)
      pos.y = size.y;
}
