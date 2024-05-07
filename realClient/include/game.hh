#ifndef GAME_HH
#define GAME_HH

#include "../../include/clientPlayerInfo.hh"

namespace ef
{
  struct Game
  {
    Game(int port, int sizex, int sizey);
    //void singleCommand(std::string str);

    std::function<void(std::string)> singleCommand;
    ef::ClientPlayerInfo cli;
    ef::Camera cam;
    bool isClick;
    bool buildMode;
    Pos lastPos;
  };
}; // !ef

#endif // GAME_HH
