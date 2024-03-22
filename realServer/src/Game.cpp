#include "game.hh"

ef::Game::Game(int port,
	       int sizex,
	       int sizey)
  :
  srv(port),
  cam(sizex, sizey, true)
{
  cam.Init("server");
  cam.ZoomIn(1);
}

