#include "game.hh"

#include <iostream>

static t_bunny_response loop(void *data)
{
  ef::Game *game = (ef::Game *)data;
  if (bunny_get_keyboard()[BKS_UP])
    {
      ef::AcuPos tempPos;
      tempPos.x = 0;
      tempPos.y = -5;
      game->cam.Move(tempPos);
    }
  if (bunny_get_keyboard()[BKS_DOWN])
    {
      ef::AcuPos tempPos;
      tempPos.x = 0;
      tempPos.y = 5;
      game->cam.Move(tempPos);
    }
  if (bunny_get_keyboard()[BKS_LEFT])
    {
      ef::AcuPos tempPos;
      tempPos.x = -5;
      tempPos.y = 0;
      game->cam.Move(tempPos);
    }
  if (bunny_get_keyboard()[BKS_RIGHT])
    {
      ef::AcuPos tempPos;
      tempPos.x = 5;
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
  if (game->isClick)
    game->cam.drawSquareSelect(game->lastPos, posi);
  if (game->buildMode)
    game->cam.drawBuildPos(game->cli.playerInfo.canPlaceBuilding(posi));
  game->cam.display(game->cli);
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
      i[2] = 200;
      i[3] = 62;
      game->cli.connectToServ(*(int *)&i, 25300);
    }
  if (sym == BKS_S)
    game->cli.sendIsReady();
  if (sym == BKS_P)
    {
      ef::Pos pos;
      t_bunny_position posi = game->cam.getMousePos();
      pos.x = posi.x;
      pos.y = posi.y;
      std::cout << "clickPos x : " << pos.x << " y : " << pos.y << std::endl;
      std::shared_ptr<ef::Building> tempBuild = game->cli.playerInfo.getBuildingAtPos(pos);
      if (tempBuild.get() != nullptr)
	game->cli.produce(tempBuild->getId(), "UnitProductor", tempBuild->getType());
    }
  if (sym == BKS_B)
    game->buildMode = !game->buildMode;
  if (sym == BKS_U)
    {
      ef::Pos pos;
      t_bunny_position posi = game->cam.getMousePos();
      pos.x = posi.x;
      pos.y = posi.y;
      std::shared_ptr<ef::Building> tempBuild = game->cli.playerInfo.getBuildingAtPos(pos);
      if (tempBuild.get() != nullptr)
	game->cli.produce(tempBuild->getId(), "missingno", tempBuild->getType());
    }
  if (sym == BKS_A)
    {
      ef::Pos posi[2];
      posi[0].x = 0;
      posi[0].y = 0;
      posi[1].x = 31;
      posi[1].y = 31;
      game->cli.select(game->cam.getSize(), posi[0], posi[1], game->singleCommand);
    }
  if (sym == BKS_M)
    {
      ef::Pos pos;
      t_bunny_position posi = game->cam.getMousePos();
      pos.x = posi.x;
      pos.y = posi.y;
      game->cli.makePath(pos, ef::WALK);
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
  if (game->buildMode == true && state == GO_DOWN)
    {
      std::cout << "clickPos x : " << posi.x << " y : " << posi.y << std::endl;
      game->cli.placeBuilding(posi);
      return GO_ON;
    }
  if (state == GO_DOWN)
    result = game->cli.man.checkClick(posi2);
  std::cout << "result : " << result << std::endl;
  if (result == 1 && but == BMB_LEFT)
    {
      if (state == GO_UP && game->isClick == true)
	{
	  game->isClick = false;
	  game->cli.select(game->cam.getSize(), game->lastPos, posi, game->singleCommand);
	}
      else if (state == GO_DOWN)
	{
	  game->lastPos.x = pos.x;
	  game->lastPos.y = pos.y;
	  game->isClick = true;
	}
    }
  if (but == BMB_RIGHT && state == GO_DOWN)
    game->cli.makePath(posi, ef::WALK);
  return GO_ON;
}

int main(int nbrin,
	 char **inputs)
{
  if (nbrin != 2)
    {
      std::cout << "How to use :\n\n./rts_client CLIENTPORT\nCLIENTPORT = the port for the client" << std::endl;
      return 0;
    }
  int port = atoi(inputs[1]);
  ef::Game game(port, 600, 600);

  bunny_set_loop_main_function(loop);
  bunny_set_key_response(key);
  bunny_set_click_response(click);
  bunny_set_display_function(display);
  game.singleCommand("azerty qwerty");
  bunny_loop(game.cam.getWin(), 60, &game);
}
