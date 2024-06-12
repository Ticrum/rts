#include "Bpixelarray.hh"
#include "resourceManager.hh"
#include <iostream>
#include <stdlib.h>
#include <time.h>
int main()
{
  /*    ef::Bpixelarray unit;
    ef::Bpixelarray build;
    bool gate = true;
    for(char i = 0; i < 10 && (gate = unit.Init(std::string("resours/sprit/errorunit.png"))); i++);
    if(gate)
    {
        std::cout << "LUL fail unit\n";
        return 1;
    }
    for(char i = 0; i < 10 && (gate = build.Init(std::string("resours/sprit/error.png"))); i++);
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
    px.Blit(build, start, size);
    
    bunny_blit(&win->buffer, px.GetClip(), NULL);
    bunny_display(win);
    sleep(1);
    start.x = 250;
    px.Blit(unit, start, size);
    
    bunny_blit(&win->buffer, px.GetClip(), NULL);
    bunny_display(win);
    sleep(1);
    start.x = 0;
    size.y = 1;
    px.Blit(build, start, size);
    
    bunny_blit(&win->buffer, px.GetClip(), NULL);
    bunny_display(win);
    sleep(1);
    start.x = 250;
    px.Blit(unit, start, size);
    
    bunny_blit(&win->buffer, px.GetClip(), NULL);
    bunny_display(win);
    sleep(1);
    size.y = 0.5;
    size.x = 0.25;
    start.y = 250;
    px.Blit(unit, start, size);
    start.x = 0;
    px.Blit(build, start, size);
    bunny_blit(&win->buffer, px.GetClip(), NULL);
    bunny_display(win);
    sleep(1);
    srand(time(NULL));
    for(char i = 0; i<10; i++)
      {
	start.x = rand()%300 + 50;
	start.y = rand()%300 + 50;
	size.x = ((double)(rand()%50)/100.0)+0.25;
	size.y = ((double)(rand()%50)/100.0)+0.25;
	px.Blit(i%2? unit: build, start, size);
	bunny_blit(&win->buffer, px.GetClip(), NULL);
	bunny_display(win);
	sleep(0.5);
      }
      sleep(1);*/
}
