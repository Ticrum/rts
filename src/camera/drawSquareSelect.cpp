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
  if (start.x > end.x)
    {
      int temp = start.x;
      start.x = end.x;
      end.x = temp;
    }
  if (start.y > end.y)
    {
      int temp = start.y;
      start.y = end.y;
      end.y = temp;
    }

  double caseSizex = (size.x / (double)mapSize.x) * zoom;
  double caseSizey = (size.y / (double)mapSize.y) * zoom;
  end.x = (end.x + 1) * caseSizex - pos.x * zoom;
  end.y = (end.y + 1) * caseSizey - pos.y * zoom;
  start.x = (start.x) * caseSizex - pos.x * zoom;
  start.y = (start.y) * caseSizey - pos.y * zoom;
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

