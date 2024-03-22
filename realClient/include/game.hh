#ifndef GAME_HH
#define GAME_HH

#include "../../include/clientPlayerInfo.hh"

namespace ef
{
  struct Game
  {
    Game(int port, int sizex, int sizey);

    ef::ClientPlayerInfo cli;
    ef::Camera cam;
    bool isClick;
    Pos lastPos;
  };
}; // !ef

#endif // GAME_HH
