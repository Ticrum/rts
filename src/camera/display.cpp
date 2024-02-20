#include "camera.hh"
#include "playerInfo.hh"

void ef::Camera::display(PlayerInfo &plr,
                         std::vector<Bpixelarray> &rsrc)
{
    if(win == NULL)
        return;
    game.Clear(0);
    plr.Display(game, rsrc, *this, true);
    bunny_blit(&win->buffer, game.GetClip(),NULL);
    bunny_blit(&win->buffer, Hud.GetClip(),NULL);
    bunny_display(win);
}
