#include "Bpixelarray.hh"

void ef::Bpixelarray::placePixel(Pos &pos,
                                 unsigned int colo)
{
    if(pos.x >= 0 && pos.x < px->clipable.buffer.width && pos.y >= 0 && pos.y < px->clipable.buffer.height)
    {
        t_bunny_color last;
        last.full = pixels[pos.x + px->clipable.buffer.width * pos.y];
        t_bunny_color color;
        color.full = colo;
        double ratio= last.argb[ALPHA_CMP]/255;
        color.argb[RED_CMP] = last.argb[RED_CMP] +ratio * (color.argb[RED_CMP]- last.argb[RED_CMP]);
        color.argb[GREEN_CMP] = last.argb[GREEN_CMP] +ratio * (color.argb[GREEN_CMP]- last.argb[GREEN_CMP]);
        color.argb[BLUE_CMP] = last.argb[BLUE_CMP] +ratio * (color.argb[BLUE_CMP]- last.argb[BLUE_CMP]);

        pixels[pos.x + px->clipable.buffer.width * pos.y] = color.full;
    }
}
