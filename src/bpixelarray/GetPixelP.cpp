#include "Bpixelarray.hh"

unsigned int &ef::Bpixelarray::GetSetPixel(unsigned int pos)
{
    if(px == NULL)
        throw(-1);
    return pixels[pos];
}
