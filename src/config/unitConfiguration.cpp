#include "unit.hh"

ef::ConfUnit::ConfUnit(std::string file)
{
    for (unsigned int i = 0; i < 10 && LoadBasic(file); i++);
}
