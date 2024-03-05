#include "Bpixelarray.hh"
#include "resourceManager.hh"
#include <iostream>
int main()
{
    ef::Bpixelarray unit;
    ef::Bpixelarray build;
    bool gate = true;
    for(char i = 0; i < 10 && (gate = unit.Init(std::string("resours/unit/sprit/error.png"))); i++);
    if(gate)
    {
        std::cout << "LUL fail unit\n";
        return 1;
    }
    for(char i = 0; i < 10 && (gate = build.Init(std::string("resours/building/sprit/error.png"))); i++);
    if(gate)
    {
        std::cout << "LUL fail build\n";
        return 1;
    }
    ef::Pos start;
    ef::AcuPos size;
    ef::Bpixelarray px;
    t_bunny_window *win;

    win = bunny_start(500,500, false, "test_size_load");
    while(px.Init(500,500));
    px.Clear(RED);
    
    bunny_blit(&win->buffer, px.GetClip(), NULL);
    bunny_display(win);
    sleep(4);
    start.x = 0;
    start.y = 0;
    size.x = 1;
    size.y = 2;
    px.Blit(unit, start, size);
    
    bunny_blit(&win->buffer, px.GetClip(), NULL);
    bunny_display(win);
    sleep(4);
    start.x = 250;
    px.Blit(build, start, size);
    
    bunny_blit(&win->buffer, px.GetClip(), NULL);
    bunny_display(win);
    sleep(4);
    start.x = 0;
    size.y = 1;
    px.Blit(build, start, size);
    
    bunny_blit(&win->buffer, px.GetClip(), NULL);
    bunny_display(win);
    sleep(4);
    start.x = 250;
    px.Blit(unit, start, size);
    
    bunny_blit(&win->buffer, px.GetClip(), NULL);
    bunny_display(win);
    sleep(4);
    size.y = 0.5;
    size.x = 0.5;
    start.y = 250;
    px.Blit(unit, start, size);
    start.x = 0;
    px.Blit(build, start, size);
    bunny_blit(&win->buffer, px.GetClip(), NULL);
    bunny_display(win);
    sleep(4);
}
