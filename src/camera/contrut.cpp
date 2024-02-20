#include "camera.hh"

ef::Camera::Camera(int width,
                   int height,
                   bool serve)
{
    zoom = 0;
    pos.x = 0;
    pos.y = 0;
    size.x = width;
    size.y = height;
    god = serve;
}
