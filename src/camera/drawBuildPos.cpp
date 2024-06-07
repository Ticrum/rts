// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 06/05/2024 13:02:38 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "camera.hh"

void ef::Camera::drawBuildPos(bool canPlaceBuild)
{
  t_bunny_position posi = getMousePos();
  AcuPos start;
  start.x = posi.x;
  start.y = posi.y;
  double caseSizex = (size.x / (double)mapSize.x) * zoom;
  double caseSizey = (size.y / (double)mapSize.y) * zoom;
  start.x = (start.x) * caseSizex - pos.x * zoom;
  start.y = (start.y) * caseSizey - pos.y * zoom;
  Pos tempPos;
  AcuPos Size;
  Size.x = caseSizex;
  Size.y = caseSizey;
  if (canPlaceBuild)
    game.rectangle(start, Size, GREEN, GREEN);
  else
    game.rectangle(start, Size, RED, RED);
}

