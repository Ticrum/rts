// EFRITS
// project:     rts
// created on:  2024-02-14 - 12:43 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: pathfinder header

#ifndef __PATHFINDER_HH__
#define __PATHFINDER_HH__

#include "object.hh"
#include "map.hh"
#include <memory>

namespace ef
{
    class Pathfinder
    {
    public:
        struct Cell
        {
            std::shared_ptr<Cell> lastCell;
            Pos pos;
            int dist;
        };

        Pathfinder(Map & baseMap);
        void resetMap(Map & baseMap);
        std::vector<Pos> makePath(Pos start, Pos end);

    private:
        void expendBorder(int mapId, int sens);
        std::shared_ptr<Cell> getConflictCell(Pos pos);

        Map map;
        int checkIndex;
        std::vector<std::shared_ptr<Cell>> checking;
    };
}; // !ef

#endif // __PATHFINDER_HH__
