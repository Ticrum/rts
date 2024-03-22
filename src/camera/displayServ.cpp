#include "camera.hh"
#include "serverPlayersInfo.hh"

#include <iostream>

void ef::Camera::display(ServerPlayersInfo &srv)
{
    if(!god ||win == NULL)
        return;
    t_bunny_color col;
    col.full = BLUE;
    col.argb[GREEN_CMP] = 0;
    game.Clear(col.full);
srv.Display(game, *this);
    bunny_blit(&win->buffer, game.GetClip(),NULL);
    //bunny_blit(&win->buffer, Hud.GetClip(),NULL);
    bunny_display(win);
}
