// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 17/05/2024 12:56:16 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "camera.hh"

#include <iostream>

void ef::Camera::finalDisplay(ClientPlayerInfo &cli)
{
  int start = clock();
  if (game.recVec.length > 0)
    bunny_set_geometry(&game.GetClip()->buffer, BGY_QUADS, (t_bunny_vertex_array *)&game.recVec, NULL);
  if (game.lineVec.length > 0)
    bunny_set_geometry(&game.GetClip()->buffer, BGY_LINES, (t_bunny_vertex_array *)&game.lineVec, NULL);
  if (game.pixVec.length > 0)
    bunny_set_geometry(&game.GetClip()->buffer, BGY_PIXELS, (t_bunny_vertex_array *)&game.pixVec, NULL);
  game.recVec.length = 0;
  game.lineVec.length = 0;
  game.pixVec.length = 0;
  bunny_blit(&win->buffer, game.GetClip(), NULL);
  bunny_display(win);
  int stop = clock();
  //std::cout << "finalDisplay time passed : " << (double)(stop - start) / CLOCKS_PER_SEC << std::endl;
}

