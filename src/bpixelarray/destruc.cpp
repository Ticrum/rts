#include"Bpixelarray.hh"

ef::Bpixelarray::~Bpixelarray()
{
    pixels.release();
    bunny_delete_clipable(&px->clipable);
}
