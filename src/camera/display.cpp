#include "camera.hh"
#include "playerInfo.hh"

void ef::Camera::display(PlayerInfo &plr)
{
    if(win == NULL)
        return;
    t_bunny_color col;
    col.full = GREEN;
    col.argb[GREEN_CMP] -= 50;
    game.Clear(col.full);
    plr.Display(game, *this, true);
    Pos pos;
    AcuPos apos;
    pos.x = 0;
    pos.y = 0;
    apos.x = game.GetSize().x;
    apos.y = game.GetSize().y;
    game.Blit(Hud, pos, apos, 1);
    bunny_blit(&win->buffer, game.GetClip(),NULL);
    Hud.Clear(4294902015);
    bunny_display(win);
}
