#include "Bpixelarray.hh"

void ef::Bpixelarray::Clear(unsigned int color)
{
    unsigned int max = px->clipable.buffer.width * px->clipable.buffer.height;
    for(unsigned int i = 0; i < max; i++)
        pixels[i] = color;
}
