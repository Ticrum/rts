#include "Bpixelarray.hh"

t_bunny_clipable *ef::Bpixelarray::GetClip()const
{
    if(px == NULL)
        throw(-1);
    return &px->clipable;
}
