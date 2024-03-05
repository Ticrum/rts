// EFRITS
// project:     rts
// created on:  2024-02-23 - 13:50 +0100
// 1st author:  romain.piccoche - romain.picoche
// description: download building configuration

#include "building.hh"

ef::ConfBuilding::ConfBuilding(std::string file)
{
    for (unsigned int i = 0; i < 10 && LoadBasic(file); i++);
}
