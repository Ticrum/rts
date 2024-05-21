#include "camera.hh"

void ef::Camera::ZoomIn(double add)
{
  if (zoom + add > 16)
    add = 16 - zoom;
  if (zoom != 0 && zoom < 16)
    {
      pos.x += (size.x - size.x / (zoom + add)) / 2 - (size.x - size.x / (zoom)) / 2;
      pos.y += (size.y - size.y / (zoom + add)) / 2 - (size.y - size.y / (zoom)) / 2;
    }
  zoom += add;
  if (zoom > 16)
    zoom = 16;
}
