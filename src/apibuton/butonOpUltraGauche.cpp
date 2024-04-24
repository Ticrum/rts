#include "apiButton.hh"

std::string ef::Buton::operator<<(std::string src)
{
  std::string toto;
  t_bunny_clipable *clip = sprit->GetClip();
  toto += "--------\nid: "  + std::to_string(id) + "\nsquare: "  +std::to_string(square.x)  + ", " + std::to_string(square.y)  + " | " +std::to_string(square.w) + ", " +std::to_string(square.h) + "\ncolor outside: "  + std::to_string(outside.full)  + "\ncolor back" + std::to_string(background.full) + "\nsprit: ";
  if(clip == NULL)
    toto += "NULL\n";
  else
    toto += std::to_string(clip->buffer.width) + ", " + std::to_string(clip->buffer.height) + "\n";
  toto += "comande: \"" + command + "\"\n--------\n";
  return toto + src;
}
