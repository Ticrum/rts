// EFRITS
// project:     rts
// created on:  2024-02-09 - 10:58 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: getImgId implementation

#include "object.hh"
#include "Bpixelarray.hh"

std::shared_ptr<ef::Bpixelarray> &ef::Object::getImg()
{
    return img;
}

