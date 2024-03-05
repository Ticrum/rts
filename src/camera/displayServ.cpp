#include "camera.hh"
#include "serverPlayersInfo.hh"

void ef::Camera::display(ServerPlayersInfo &srv,
                         std::vector<std::shared_ptr<ef::Bpixelarray>> &rsrc)
{
    if(!god ||win == NULL)
        return;
    game.Clear(0);
    srv.Display(game, rsrc, *this);
    bunny_blit(&win->buffer, game.GetClip(),NULL);
    bunny_blit(&win->buffer, Hud.GetClip(),NULL);
    bunny_display(win);
}
