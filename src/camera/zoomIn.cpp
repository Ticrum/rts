#include "camera.hh"

void ef::Camera::ZoomIn(double add)
{
  if (zoom != 0)
    {
      double ratio = add / zoom;
      pos.x += (size.x / 4 / zoom) * ratio;
      pos.y += (size.y / 4 / zoom) * ratio;
    }
  zoom += add;
}
