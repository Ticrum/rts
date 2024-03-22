#include "game.hh"

ef::Game::Game(int port,
	       int sizex,
	       int sizey)
  :
  cli(port, 0),
  cam(sizex, sizey),
  isClick(false)
{
  cam.Init("client");
  cam.ZoomIn(1);
  lastPos.x = -1;
  lastPos.y = -1;
}
