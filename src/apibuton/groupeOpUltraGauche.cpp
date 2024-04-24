#include "apiButton.hh"

std::string ef::Groupe::operator<<(std::string src)
{
  std::string toto;
  toto += std::string("___---") +std::string((Case? "Case" : " Px ")) + "---___\nlastId: " + std::to_string(Id) + "\nhit box: " + std::to_string(min.x)  + ", " + std::to_string(min.y)  + " / " +std::to_string(max.x) + ", " +std::to_string(max.y) + "\n";
  for(unsigned int j = 0; j < buton.size(); ++j)
      toto+= buton[j]<< "";
  toto += "---__________---\n";
  return toto + src;
}
