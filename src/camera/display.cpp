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

#include <iostream>

void ef::Camera::display(ClientPlayerInfo &cli)
{
  if(win == NULL)
    return;
  t_bunny_color col;
  col.full = GREEN;
  col.argb[GREEN_CMP] -= 50;
  game.Clear(col.full);
  cli.playerInfo.Display(game, *this, true);
  //for (int i = 0; i < tempBuilds.size(); i += 1)
  //  tempBuilds[i]->displayButon(cli.man, func, cli.res.getSprit());
  cli.updateSelectedInfo();
  cli.man.print(game);
  t_bunny_position posi;
  posi.x = 20;
  posi.y = 0;
  drawText(game, cli.res.getSprit()["font.png"], cli.playerInfo.getMoney(), posi);
  //cli.man.printTerminal();
  Pos pos;
  AcuPos apos;
  pos.x = 0;
  pos.y = 0;
  apos.x = game.GetSize().x;
  apos.y = game.GetSize().y;
  //game.Blit(Hud, pos, apos, 1);
}
