#include "Bpixelarray.hh"

ef::Pos ef::Bpixelarray::GetSize()
{
    Pos pos;

    if(px != NULL)
    {
        pos.x = px->clipable.buffer.width;
        pos.y = px->clipable.buffer.height;
    }
    else
    {
        pos.x = -1;
        pos.y = -1;
    }
    return pos;
}
