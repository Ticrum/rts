#ifndef GAME_HH
#define GAME_HH

#include "../../include/serverPlayersInfo.hh"

namespace ef
{
  struct Game
  {
    Game(int port, int sizex, int sizey);

    ef::ServerPlayersInfo srv;
    ef::Camera cam;
    int startTime;
    int stop;
  };
}; // !ef

#endif // GAME_HH
