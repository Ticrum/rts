#include "game.hh"

ef::Game::Game(int port,
	       int sizex,
	       int sizey)
  :
  srv(port),
  cam(sizex, sizey, true),
  startTime(0),
  stop(0)
{
  cam.Init("server");
  cam.ZoomIn(1);
}

