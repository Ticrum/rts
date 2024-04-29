// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 24/04/2024 15:15:58 ******************************************************
// romain.piccoche <romain.picoche@laika.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

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
    bunny_blit(&win->buffer, game.GetClip(),NULL);
    //bunny_blit(&win->buffer, Hud.GetClip(),NULL);
    bunny_display(win);
}
