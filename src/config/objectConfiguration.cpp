#include "object.hh"

ef::ConfObj::ConfObj(std::string file)
    :imgId(-1)
{
    for (unsigned int i = 0; i < 10 && LoadBasic(file); i++);
}
