#include "game.hh"

#include <iostream>

ef::Game::Game(int port,
	       int sizex,
	       int sizey,
	       bool isIa)
  :
  cli(port, 0),
  cam(sizex, sizey),
  isClick(false),
  buildMode(false),
  lastClick(0),
  firstBuildLoad(false),
  startTime(0),
  stop(0)
{
  singleCommand = [&](std::string str)
  {
    std::cout << "single command pass" << std::endl;
    std::vector<std::string> args;
    int i = 0;
    while ((i = str.find(" ")) != (int)std::string::npos)
      {
	args.push_back(str.substr(0, i));
	str.erase(0, i + 1);
      }
    args.push_back(str);
    if (args.size() <= 0)
      return;
    if (args[0] == "connect")
      {
	if (args.size() != 3)
	  return;
	int ip = std::stoi(args[1]);
	int port = std::stoi(args[2]);
	cli.connectToServ(ip, port);
      }
    else if (args[0] == "stopUnit")
      cli.stopUnit();
    else if (args[0] == "setTarget")
      {
	Pos tempPos;
	t_bunny_position posi = cam.getMousePos();
	tempPos.x = posi.x;
	tempPos.y = posi.y;
	cli.setTarget(tempPos);
      }
    else if (args[0] == "produce")
      {
	Pos tempPos;
	if (args.size() != 2)
	  return;
	cli.produce(args[1]);
      }
    else if (args[0] == "destroy")
      {
	cli.destroyUnit();
	cli.destroyBuilding();
      }
    else if (args[0] == "sendIsReady")
      cli.sendIsReady();
    else if (args[0] == "cancel")
      cli.cancel();
  };
  char j;
  for(int i = 0; i < 10 && (j = cam.Init("client")) != 0; i++)
    std::cout<< "game construct " << std::to_string(j) << std::endl;
  cam.ZoomIn(1);
  lastPos.x = -1;
  lastPos.y = -1;
  if (isIa)
    ia.reset(new Ia(1, 1, 1, 1, cli, singleCommand, cam.getSize()));
  else
    ia = nullptr;
}
