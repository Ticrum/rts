#include "Bpixelarray.hh"

bool ef::Bpixelarray::Init(unsigned int width,
                           unsigned int height)
{
    if(px != NULL)
    {
        pixels.release();
        bunny_delete_clipable(&px->clipable);
    }
    if((px = bunny_new_pixelarray(width, height)) == NULL)
        return true;

    std::unique_ptr<unsigned int[]> tmp ((unsigned int *)px->pixels);

    pixels = std::move(tmp);
    return false;
}