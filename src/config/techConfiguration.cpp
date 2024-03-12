#include "building.hh"

ef::Tech::Tech(std::string file)
  :Tech()
{
  for (unsigned int i = 0; i < 10 && load(file); i++);
}
