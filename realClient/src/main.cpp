#include "game.hh"

#include <iostream>

static t_bunny_response loop(void *data)
{
  ef::Game *game = (ef::Game *)data;
  game->startTime = clock();
  if (game->ia != nullptr && game->cli.isGameStarted())
    {
      if (!game->firstBuildLoad)
	{
	  game->ia->getMainBuild();
	  game->firstBuildLoad = true;
	}
      game->ia->compute(0.016);
    }
  const t_bunny_position *pos = bunny_get_mouse_position();
  double speed = 7.0 / game->cam.getZoom();
  if (speed < 1)
    speed = 1;
  if (bunny_get_keyboard()[BKS_UP] || pos->y < 20)
    {
      ef::AcuPos tempPos;
      tempPos.x = 0;
      tempPos.y = -speed;
      game->cam.Move(tempPos);
    }
  if (bunny_get_keyboard()[BKS_DOWN] || pos->y > game->cam.getSize().y - 20)
    {
      ef::AcuPos tempPos;
      tempPos.x = 0;
      tempPos.y = speed;
      game->cam.Move(tempPos);
    }
  if (bunny_get_keyboard()[BKS_LEFT] || pos->x < 20)
    {
      ef::AcuPos tempPos;
      tempPos.x = -speed;
      tempPos.y = 0;
      game->cam.Move(tempPos);
    }
  if (bunny_get_keyboard()[BKS_RIGHT] || pos->x > game->cam.getSize().x - 20)
    {
      ef::AcuPos tempPos;
      tempPos.x = speed;
      tempPos.y = 0;
      game->cam.Move(tempPos);
    }
  game->cli.computeActions(0.016);
  return GO_ON;
}

static t_bunny_response display(void *data)
{
  ef::Game *game = (ef::Game *)data;
  t_bunny_position pos = game->cam.getMousePos();
  ef::Pos posi;
  posi.x = pos.x;
  posi.y = pos.y;
  game->cam.display(game->cli);
  if (game->isClick)
    game->cam.drawSquareSelect(game->lastPos, posi);
  if (game->buildMode)
    game->cam.drawBuildPos(game->cli.playerInfo.canPlaceBuilding(posi));
  game->cam.finalDisplay(game->cli);
  game->stop = clock();
  game->cli.stockPacket(0.014 - ((double)(game->stop - game->startTime) / CLOCKS_PER_SEC));
  return GO_ON;
}

static t_bunny_response key(t_bunny_event_state state,
			    t_bunny_keysym sym,
			    void *data)
{
  ef::Game *game = (ef::Game *)data;
  if (state == GO_UP)
    return GO_ON;
  if (sym == BKS_ESCAPE)
    return EXIT_ON_SUCCESS;
  if (sym == BKS_C)
    {
      char i[4];
      i[0] = 192;
      i[1] = 168;
      i[2] = 188;
      i[3] = 129;
      game->cli.connectToServ(*(int *)&i, 64841);
    }
  if (sym == BKS_S)
    game->cli.sendIsReady();
  if (sym == BKS_B)
    game->buildMode = !game->buildMode;
  if (sym == BKS_A)
    {
      ef::Pos posi[2];
      posi[0].x = 0;
      posi[0].y = 0;
      posi[1].x = 63;
      posi[1].y = 63;
      game->cli.select(game->cam.getSize(), posi[0], posi[1], game->singleCommand, false);
    }
  if (sym == BKS_I)
    game->cam.ZoomIn(game->cam.getZoom());
  if (sym == BKS_O)
    game->cam.ZoomOut(game->cam.getZoom() / 2);
  return GO_ON;
}

static t_bunny_response click(t_bunny_event_state state,
			      t_bunny_mouse_button but,
			      void *data)
{
  ef::Game *game = (ef::Game *)data;
  t_bunny_position pos = game->cam.getMousePos();
  ef::Pos posi;
  posi.x = pos.x;
  posi.y = pos.y;
  ef::Pos posi2;
  const t_bunny_position *pos2 = bunny_get_mouse_position();
  posi2.x = pos2->x;
  posi2.y = pos2->y;
  int result = 1;
  if (but == BMB_MIDDLE && state == GO_DOWN)
    game->buildMode = !game->buildMode;
  if (game->buildMode == true && state == GO_DOWN && but == BMB_LEFT)
    {
      //std::cout << "clickPos x : " << posi.x << " y : " << posi.y << std::endl;
      game->cli.placeBuilding(posi);
      return GO_ON;
    }
  if (state == GO_DOWN && !game->buildMode)
    result = game->cli.man.checkClick(posi2);
  //std::cout << "result : " << result << std::endl;
  if (pos2->y > (game->cam.getSize().y * 0.3) * 2.35 &&
      pos2->y < game->cam.getSize().y &&
      pos2->x < game->cam.getSize().x * 0.3 &&
      pos2->x > 0)
    {
      if (but == BMB_LEFT && state == GO_DOWN)
	{
	  ef::AcuPos minimapPos;
	  minimapPos.x = pos2->x / 0.3;
	  minimapPos.y = (pos2->y - ((game->cam.getSize().y * 0.3) * 2.35)) / 0.3;
	  minimapPos.x = minimapPos.x - game->cam.getPos().x - ((game->cam.getSize().x / game->cam.getZoom()) / 2);
	  minimapPos.y = minimapPos.y - game->cam.getPos().y - ((game->cam.getSize().y / game->cam.getZoom()) / 2);
	  game->cam.Move(minimapPos);
	}
    }
  else
    {
      if (result == 1 && but == BMB_LEFT)
	{
	  if (state == GO_UP && game->isClick == true)
	    {
	      game->isClick = false;
	      if ((double)(clock() - game->lastClick) / CLOCKS_PER_SEC < 0.18)
		game->cli.select(game->cam.getSize(), game->lastPos, posi, game->singleCommand, true);
	      else
		{
		  game->cli.select(game->cam.getSize(), game->lastPos, posi, game->singleCommand, false);
		  game->lastClick = clock();
		}
	    }
	  else if (state == GO_DOWN)
	    {
	      game->lastPos.x = pos.x;
	      game->lastPos.y = pos.y;
	      game->isClick = true;
	    }
	}
      if (but == BMB_RIGHT && state == GO_DOWN)
	{
	  if ((double)(clock() - game->lastClick) / CLOCKS_PER_SEC < 0.18)
	    game->cli.makePath(posi, ef::RUN);
	  else
	    {
	      game->cli.makePath(posi, ef::WALK);
	      game->cli.setTarget(posi);
	      game->lastClick = clock();
	    }
	}
    }
  return GO_ON;
}

static t_bunny_response wheel(int wheelid,
			      int delta,
			      void *data)
{
  ef::Game *game = (ef::Game *)data;

  //std::cout << "delta : " << delta << std::endl;
  if (delta == 1)
    game->cam.ZoomIn(game->cam.getZoom() / 4.0);
  if (delta == -1)
    game->cam.ZoomOut((game->cam.getZoom() / 5.0));
  return GO_ON;
}

int main(int nbrin,
	 char **inputs)
{
  if (nbrin != 3)
    {
      std::cout << "How to use :\n\n./rts_client CLIENTPORT ISIA\nCLIENTPORT = the port for the client\nISIA = '1' for true '0' for false" << std::endl;
      return 0;
    }
  int port = atoi(inputs[1]);
  bool isIa = false;
  if (inputs[2][0] == '1')
    isIa = true;
  static ef::Game game(port, 1920, 1080, isIa);

  bunny_set_loop_main_function(loop);
  bunny_set_key_response(key);
  bunny_set_click_response(click);
  bunny_set_display_function(display);
  bunny_set_wheel_response(wheel);
  bunny_loop(game.cam.getWin(), 60, &game);
}
