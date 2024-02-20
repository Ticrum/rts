#include "camera.hh"

void ef::Camera::Move(AcuPos move)
{
    pos.x += move.x;
    pos.y += move.y;
}
