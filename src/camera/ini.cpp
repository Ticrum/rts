#include "camera.hh"
#include <iostream>

int ef::Camera::Init(std::string screen)
{
    bool gate;
    std::cout<< size.x << "| "<< size.y<< "\n";
    for(char i= 0; i<20 && (gate = game.Init(size.x, size.y)); i ++);
    if(gate)
      return 1;
    for(char i= 0; i<20 && (gate = Hud.Init(size.x, size.y)); i ++);
    if(gate)
      return 2;
    if((win = bunny_start(size.x, size.y, false, (god)? &(screen + "_serveur_rts")[0]: &(screen + "_client_rts")[0])) == NULL)
        return 3;
    main = bunny_new_picture(size.x, size.y);
    return 0;
}
