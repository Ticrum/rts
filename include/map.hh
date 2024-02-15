#ifndef __MAP_HH__
#define __MAP_HH__

#include "object.hh"

namespace ef
{
    class Map
    {
    public:
        Map(int sizex, int sizey);
        Pos getMapSize();
        char & operator[](int index);
        void clear(char data);

    private:
        std::vector<char> map;
        Pos mapSize;
    };
}; // !ef

#endif // __MAP_HH__
