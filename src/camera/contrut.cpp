#include "camera.hh"

ef::Camera::Camera(int width,
                   int height,
                   bool serve)
  :zoom(0),
   god(serve)
{
  pos.x = 0;
  pos.y = 0;
  size.x = width;
  size.y = height;
  mapSize.x = 64;
  mapSize.y = 64;
}
