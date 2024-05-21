#include "Bpixelarray.hh"
#include <iostream>
bool ef::Bpixelarray::Init(unsigned int width,
                           unsigned int height)
{
    if(px != NULL)
    {
      std::cout << "supram" << width << "| " << height<< "\n";
      pixels.release();
      //bunny_delete_clipable(&px->clipable);
      bunny_delete_clipable(px);
    }
    std::cout <<"création "<<  width << "| " << height<< "\n";

    if((px = bunny_new_picture(width, height)) == NULL)
      return true;
    //std::unique_ptr<unsigned int[]> tmp ((unsigned int *)px->pixels);

    //pixels = std::move(tmp);
    recVec.length = 0;
    lineVec.length = 0;
    pixVec.length = 0;
    return false;
}
