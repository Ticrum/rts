// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 25/04/2024 12:35:51 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "camera.hh"

#include <iostream>

void ef::Camera::drawSquareSelect(Pos start,
				  Pos end)
{
  double caseSize = (size.x / (double)mapSize.x) * zoom;
  end.x = (end.x) * caseSize - pos.x;
  end.y = (end.y) * caseSize - pos.y;
  start.x = (start.x) * caseSize - pos.x;
  start.y = (start.y) * caseSize - pos.y;
  unsigned int in = RED;
  unsigned int out = GREEN;
  Pos tempPos = start;
  while (tempPos.x < end.x)
    {
      Hud.placePixel(tempPos, GREEN);
      tempPos.x += 1;
    }
  while (tempPos.y < end.y)
    {
      Hud.placePixel(tempPos, GREEN);
      tempPos.y += 1;
    }
  while (tempPos.x > start.x)
    {
      Hud.placePixel(tempPos, GREEN);
      tempPos.x -= 1;
    }
  while (tempPos.y > start.y)
    {
      Hud.placePixel(tempPos, GREEN);
      tempPos.y -= 1;
    }
}

