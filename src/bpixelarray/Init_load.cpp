#include "Bpixelarray.hh"

bool ef::Bpixelarray::Init(std::string file)
{
    if(px != NULL)
    {
        pixels.release();
        bunny_delete_clipable(&px->clipable);
    }
    if((px = bunny_load_pixelarray(&file[0])) == NULL)
      if((px = bunny_load_pixelarray("FUCK.png")) == NULL)
	 return true;
    std::unique_ptr<unsigned int[]> tmp ((unsigned int *)px->pixels);

    pixels = std::move(tmp);
    return false;
}
