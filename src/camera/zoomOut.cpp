#include "camera.hh"

void ef::Camera::ZoomOut(double sub)
{
  if (zoom - sub < 1)
    sub = zoom - 1;
  if (zoom != 0 && zoom > 1)
    {
      pos.x -= (size.x - size.x / zoom) / 2 - (size.x - size.x / (zoom - sub)) / 2;
      pos.y -= (size.y - size.y / zoom) / 2 - (size.y - size.y / (zoom - sub)) / 2;
    }
  zoom -= sub;
  if (zoom < 1)
    zoom = 1;
}
