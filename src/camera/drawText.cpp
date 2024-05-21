// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 02/05/2024 18:09:27 ******************************************************
// thomas.barbe <thomas.barbe@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "camera.hh"

static void print_char(ef::Bpixelarray &pix,
                       ef::Bpixelarray &font,
                       char c,
                       t_bunny_position pos)
{
  int x;
  int y;
  ef::Pos temp;
  unsigned int color;

  ef::VertexArray<5> tempV;
  tempV.length = 4;
  tempV.vertex[0].pos.x = pos.x;
  tempV.vertex[0].pos.y = pos.y;
  tempV.vertex[0].tex.x = c * 10;
  tempV.vertex[0].tex.y = 0;
  tempV.vertex[1].pos.x = pos.x + 10;
  tempV.vertex[1].pos.y = pos.y;
  tempV.vertex[1].tex.x = c * 10 + 10;
  tempV.vertex[1].tex.y = 0;
  tempV.vertex[2].pos.x = pos.x + 10;
  tempV.vertex[2].pos.y = pos.y + 14;
  tempV.vertex[2].tex.x = c * 10 + 10;
  tempV.vertex[2].tex.y = 14;
  tempV.vertex[3].pos.x = pos.x;
  tempV.vertex[3].pos.y = pos.y + 14;
  tempV.vertex[3].tex.x = c * 10;
  tempV.vertex[3].tex.y = 14;
  bunny_set_geometry(&pix.GetClip()->buffer, BGY_QUADS, (t_bunny_vertex_array *)&tempV, font.GetClip());

  /*
  y = 0;
  while (y < 14)
    {
      x = 0;
      while (x < 10)
        {
	  
	  color = font.GetSetPixel(x + c * 10, y);//px[x + (c * 10) + (y * font->clipable.buffer.width)];
	  //printf("col %u %u\n", color, WHITE);
	  if (color == 4290013695)
            {
	      temp.x = pos.x + x;
	      temp.y = pos.y + y;
	      pix.placePixel(temp, GREEN);
            }
	  x += 1;
        }
      y += 1;
    }
  */
}

void ef::Camera::drawText(Bpixelarray &pix,
			  Bpixelarray &font,
			  std::string str,
			  t_bunny_position pos)
{
  int compt;
  int cumul;

  compt = 0;
  cumul = 0;
  while (compt < (int)str.size())
    {
      if (str[compt] == '\n')
        {
	  pos.y += 16;
	  pos.x -= 10 * cumul;
	  cumul = 0;
        }
      else
        {
	  print_char(pix, font, str[compt], pos);
	  cumul += 1;
	  pos.x += 10;
        }
      compt += 1;
    }
}
