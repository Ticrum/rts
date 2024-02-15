// EFRITS
// project:     rts
// created on:  2024-02-14 - 17:57 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: pathfinder test

#include "pathfinder.hh"

static void printMap(ef::Map map)
{
    for (int i = 0; i < map.getMapSize().x * map.getMapSize().y; i += 1)
    {
        if (i % map.getMapSize().x == 0)
            printf("\n");
        printf("%c", map[i] + '0');
    }
}

int main(void)
{
    srand(time(NULL));
    ef::Map map(128, 128);
    map.clear(0);

    for (int i = 0; i < 1400; i += 1)
        map[rand() % (map.getMapSize().x * map.getMapSize().y)] = 1;
    map[4 + 10 * 5] = 1;
    map[5 + 10 * 5] = 1;
    map[6 + 10 * 5] = 1;
    map[7 + 10 * 5] = 1;
    map[8 + 10 * 5] = 1;


    ef::Pathfinder path(map);
    ef::Pos start;
    ef::Pos end;

    start.x = 0;
    start.y = 0;
    end.x = map.getMapSize().x - 2;
    end.y = map.getMapSize().y - 1;
    std::vector<ef::Pos> temp = path.makePath(start, end);
    for (int i = 0; i < (int)temp.size(); i += 1)
        map[temp[i].x + temp[i].y * map.getMapSize().x] = 9;
    printMap(map);
    printf("pas dedans\n");
}

