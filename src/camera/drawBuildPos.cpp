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
  Pos start;
  start.x = posi.x;
  start.y = posi.y;
  double caseSize = (size.x / (double)mapSize.x) * zoom;
  start.x = (start.x) * caseSize - pos.x * zoom;
  start.y = (start.y) * caseSize - pos.y * zoom;
  Pos tempPos;
  for (int x = start.x; x < start.x + caseSize; x += 1)
    for (int y = start.y; y < start.y + caseSize; y += 1)
      {
	tempPos.x = x;
	tempPos.y = y;
	if (canPlaceBuild)
	  Hud.placePixel(tempPos, GREEN);
	else
	  Hud.placePixel(tempPos, RED);
      }
}

