#include "object.hh"

ef::ConfObj::ConfObj(std::string file)
  :maxhp(-1)
{
    for (unsigned int i = 0; i < 10 && LoadBasic(file); i++);
}
