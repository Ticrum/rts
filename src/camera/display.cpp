#include "camera.hh"
#include "playerInfo.hh"

void ef::Camera::display(PlayerInfo &plr)
{
    if(win == NULL)
        return;
    game.Clear(BLACK);
    plr.Display(game, *this, true);
    bunny_blit(&win->buffer, game.GetClip(),NULL);
    //    bunny_blit(&win->buffer, Hud.GetClip(),NULL);
    bunny_display(win);
}
