// EFRITS
// project:     rts
// created on:  2024-02-26 - 11:59 +0100
// 1st author:  romain.piccoche - romain.picoche
// description: constructor by copy

#include "object.hh"

ef::ConfObj::ConfObj(ConfObj const &other)
    :imgId(other.imgId),
     objSize(other.objSize),
     maxhp(other.maxhp),
     armor(other.armor),
     rangeOfVision(other.rangeOfVision),
     conf(other.conf)
{
    for(unsigned int i = 0; i < conf.size(); i++)
        conformConf[i] = conf[i];
}
