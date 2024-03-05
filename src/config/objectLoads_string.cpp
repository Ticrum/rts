// EFRITS
// project:     rts
// created on:  2024-02-23 - 10:44 +0100
// 1st author:  romain.piccoche - romain.picoche
// description: load object config

#include "object.hh"
#include "Bconf.hh"

int ef::ConfObj::LoadBasic(std::string &file)
{
    Bconf conff(file);
    if(conff())
        for(unsigned int i = 0; i < 10 && conff.retry(file); i++);
    if(conff())
        return 1;
    return LoadBasic(conff);
}
