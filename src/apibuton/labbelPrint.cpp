// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 23/05/2024 11:51:15 ******************************************************
// romain.piccoche <romain.picoche@laika.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "apiButton.hh"
#include <iostream>

void ef::Labbel::print(ef::Bpixelarray &pix)
{
  t_bunny_clipable *clip = font->GetClip();
  if(clip != NULL)
    {
      unsigned int i;
      int charSize = (((double)clip->buffer.width) / 127.0);
      if(4 * text.size() > 800)
	text = "text is too big";
      ef::VertexArray<800> tempV;
      // tempV.length = 800;
      for(i = 0; i < text.size(); ++i)
	{
	  tempV.vertex[0 + 4 * i].pos.x = square.x + i * charSize * square.w;
	  tempV.vertex[0 + 4 * i].pos.y = square.y;
	  tempV.vertex[0 + 4 * i].tex.x = text[i] * charSize;
	  tempV.vertex[0 + 4 * i].tex.y = 0;
	  tempV.vertex[1 + 4 * i].pos.x = square.x + i * charSize * square.w + charSize * square.w;
	  tempV.vertex[1 + 4 * i].pos.y = square.y;
	  tempV.vertex[1 + 4 * i].tex.x = charSize + text[i] * charSize;
	  tempV.vertex[1 + 4 * i].tex.y = 0;
	  tempV.vertex[2 + 4 * i].pos.x = square.x + i * charSize * square.w + charSize * square.w;
	  tempV.vertex[2 + 4 * i].pos.y = square.y + clip->buffer.height * square.h;
	  tempV.vertex[2 + 4 * i].tex.x = charSize + text[i] * charSize;
	  tempV.vertex[2 + 4 * i].tex.y = clip->buffer.height;
	  tempV.vertex[3 + 4 * i].pos.x = square.x + i * charSize * square.w;
	  tempV.vertex[3 + 4 * i].pos.y = square.y + clip->buffer.height * square.h;
	  tempV.vertex[3 + 4 * i].tex.x = text[i] * charSize;
	  tempV.vertex[3 + 4 * i].tex.y = clip->buffer.height;
	}
      /*std::cout<<"\""<< text <<"\"\n0 : " << tempV.vertex[0].pos.x << " | " << tempV.vertex[0].pos.y<< "   " <<
	tempV.vertex[0].tex.x << " | " << tempV.vertex[0].tex.y<<
	"\n1 : " << tempV.vertex[1].pos.x << " | " << tempV.vertex[1].pos.y<< "   " <<
	tempV.vertex[1].tex.x << " | " << tempV.vertex[1].tex.y<<
	"\n2 : " << tempV.vertex[2].pos.x << " | " << tempV.vertex[2].pos.y<< "   " <<
	tempV.vertex[2].tex.x << " | " << tempV.vertex[2].tex.y<<
	"\n3 : " << tempV.vertex[3].pos.x << " | " << tempV.vertex[3].pos.y<< "   " <<
	tempV.vertex[3].tex.x << " | " << tempV.vertex[3].tex.y<<std::endl;*/
      tempV.length = i*4;
      bunny_set_geometry(&pix.GetClip()->buffer, BGY_QUADS, (t_bunny_vertex_array *)&tempV, font->GetClip());
    }
}
