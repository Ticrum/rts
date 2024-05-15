#include "camera.hh"

void ef::Camera::ZoomOut(double sub)
{
  if (zoom != 0 && zoom > 1)
    {
      double ratio = sub / (zoom - sub);
      pos.x -= (size.x / 4 / (zoom - sub)) * ratio;
      pos.y -= (size.y / 4 / (zoom - sub)) * ratio;
    }
  zoom -= sub;
  if (zoom < 1)
    zoom = 1;
}
