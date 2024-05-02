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
#include "clientPlayerInfo.hh"

void ef::Camera::display(ClientPlayerInfo &cli)
{
    if(win == NULL)
        return;
    t_bunny_color col;
    col.full = GREEN;
    col.argb[GREEN_CMP] -= 50;
    game.Clear(col.full);
    cli.playerInfo.Display(game, *this, true);
    std::vector<std::shared_ptr<Building>> tempBuilds = cli.getSelectedBuildings();
    //for (int i = 0; i < tempBuilds.size(); i += 1)
    //  tempBuilds[i]->displayButon(cli.man, func, cli.res.getSprit());
    cli.man.print(Hud);
    //cli.man.printTerminal();
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
