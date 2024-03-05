#include "object.hh"

ef::Pos &ef::Pos::operator=(Pos const& other)
{
    x = other.x;
    y = other.y;
    return *this;
}
