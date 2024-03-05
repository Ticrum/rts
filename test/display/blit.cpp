#include "Bpixelarray.hh"
#include <iostream>

int main()
{
    t_bunny_window *win;

    win = bunny_start(500,500, false, "test_blit");
    ef::Bpixelarray px;
    ef::Bpixelarray blu;
    ef::Bpixelarray whi;
    ef::Bpixelarray red;
    while(px.Init(500, 500));
    while(blu.Init(200, 100));
    while(whi.Init(300, 100));
    while(red.Init(1000, 100));
    px.Clear(BLACK);
    ef::Pos size = px.GetSize();
    if(size.x != 500 || size.y != 500)
    {
        std::cout << "ERROR: FAULS SIZE ("<< size.x << ", "<<  size.y<< ")\n";
        return 1;
    }
    size = blu.GetSize();
    for(int i = 0; i< size.x *size.y; i++)
        blu.GetSetPixel(i) = BLUE;
    size = red.GetSize();
    for(int i = 0; i< size.x *size.y; i++)
        red.GetSetPixel(i) = RED;
    size = whi.GetSize();
    for(int i = 0; i< size.x *size.y; i++)
        whi.GetSetPixel(i) = WHITE;
    ef::AcuPos siz;
    siz.x = 1;
    siz.y = 1;
    size.x = 0;
    size.y = 200;
    px.Blit(red, size, siz);
    px.Blit(whi, size, siz);
    px.Blit(blu, size, siz);
    bunny_blit(&win->buffer, px.GetClip(), NULL);
    bunny_display(win);
    sleep(10);
}

