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
  end.x = (end.x + 1) * caseSize - pos.x * zoom;
  end.y = (end.y + 1) * caseSize - pos.y * zoom;
  start.x = (start.x) * caseSize - pos.x * zoom;
  start.y = (start.y) * caseSize - pos.y * zoom;
  Pos tempPos = start;
  while (tempPos.x < end.x)
    {
      game.placePixel(tempPos, GREEN);
      tempPos.x += 1;
    }
  while (tempPos.y < end.y)
    {
      game.placePixel(tempPos, GREEN);
      tempPos.y += 1;
    }
  while (tempPos.x > start.x)
    {
      game.placePixel(tempPos, GREEN);
      tempPos.x -= 1;
    }
  while (tempPos.y > start.y)
    {
      game.placePixel(tempPos, GREEN);
      tempPos.y -= 1;
    }
}

