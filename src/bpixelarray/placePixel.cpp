#include "Bpixelarray.hh"

void ef::Bpixelarray::placePixel(Pos &pos,
                                 unsigned int colo)
{
    if(pos.x >= 0 && pos.x < px->clipable.buffer.width && pos.y >= 0 && pos.y < px->clipable.buffer.height)
        pixels[pos.x + px->clipable.buffer.width * pos.y] = colo;
}
