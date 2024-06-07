#ifndef GAME_HH
#define GAME_HH

#include "ia.hh"

namespace ef
{
  struct Game
  {
    Game(int port, int sizex, int sizey, bool isIa);
    //void singleCommand(std::string str);

    std::shared_ptr<Ia> ia;
    std::function<void(std::string)> singleCommand;
    ef::ClientPlayerInfo cli;
    ef::Camera cam;
    bool isClick;
    bool buildMode;
    Pos lastPos;
    int lastClick;
    bool firstBuildLoad;
    int startTime;
    int stop;
  };
}; // !ef

#endif // GAME_HH
