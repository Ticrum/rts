#include "object.hh"

ef::ConfObj &ef::ConfObj::operator=(ConfObj const&other)
{
    img = other.img;
    objSize = other.objSize;
    maxhp = other.maxhp;
    armor = other.armor;
    rangeOfVision = other.rangeOfVision;
    conf= other.conf;
    for(unsigned int i = 0; i < conf.size(); i++)
        conformConf[i] = conf[i];
    return *this;
}
