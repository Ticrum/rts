#include "camera.hh"

bool ef::Camera::Init(std::string screen)
{
    bool gate;
    for(char i= 0; i<20 && (gate = game.Init(size.x, size.y)); i ++);
    if(gate)
        return true;
    for(char i= 0; i<20 && (gate = game.Init("resource/hud.jpg")); i ++);
    if(gate)
        return true;
    if((win = bunny_start(size.x, size.y, false, (god)? &(screen + "_serveur_rts")[0]: &(screen + "_client_rts")[0])) == NULL)
        return true;
    return false;
}
