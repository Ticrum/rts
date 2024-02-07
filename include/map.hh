#ifndef __MAP_HH__
#define __MAP_HH__

#include "object.hh"

namespace ef
{
    class Map
    {
    public:
        Map();
        Pos getMapSize();
        & char operator[]();

    private:
        vector<char> map;
        Pos mapSize;
    };
}; // !ef

#endif // __MAP_HH__
