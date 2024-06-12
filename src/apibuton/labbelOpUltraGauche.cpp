// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 23/05/2024 11:32:57 ******************************************************
// romain.piccoche <romain.picoche@laika.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "apiButton.hh"

std::string ef::Labbel::operator<<(std::string src)
{
  t_bunny_clipable *clip = font->GetClip();
  std::string toto = "------------\npos: "+std::to_string(square.x)+" | "+std::to_string(square.y)+"\nsize: "+std::to_string(square.w)+" | "+std::to_string(square.h)+"\ntext: "+ text;
  if(clip == NULL)
    toto += "NULL\n";
  else
    toto += std::to_string(clip->buffer.width) + ", " + std::to_string(clip->buffer.height) + "\n";
  return toto + "------------\n" + src;
}
