// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 21/03/2024 15:52:51 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "camera.hh"

t_bunny_position ef::Camera::getMousePos()
{
  t_bunny_position posa;
  const t_bunny_position *posi = bunny_get_mouse_position();

  posa.x = (posi->x + pos.x) * ((double)mapSize.x / ((double)size.x * zoom));
  posa.y = (posi->y + pos.y) * ((double)mapSize.y / ((double)size.y * zoom));
  return posa;
}

