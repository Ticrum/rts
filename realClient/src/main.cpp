#include "game.hh"

#include <iostream>

static t_bunny_response loop(void *data)
{
  ef::Game *game = (ef::Game *)data;
  game->cli.computeActions(0.016);
  return GO_ON;
}

static t_bunny_response display(void *data)
{
  ef::Game *game = (ef::Game *)data;
  game->cam.display(game->cli.playerInfo);
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
      i[0] = 127;
      i[1] = 0;
      i[2] = 0;
      i[3] = 1;
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
    {
      ef::Pos pos;
      t_bunny_position posi = game->cam.getMousePos();
      pos.x = posi.x;
      pos.y = posi.y;
      std::cout << "clickPos x : " << pos.x << " y : " << pos.y << std::endl;
      game->cli.placeBuilding(pos);
    }
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
      game->cli.select(posi[0], posi[1]);
    }
  if (sym == BKS_M)
    {
      ef::Pos pos;
      t_bunny_position posi = game->cam.getMousePos();
      pos.x = posi.x;
      pos.y = posi.y;
      game->cli.makePath(pos, ef::WALK);
    }
  return GO_ON;
}

static t_bunny_response click(t_bunny_event_state state,
			      t_bunny_mouse_button but,
			      void *data)
{
  ef::Game *game = (ef::Game *)data;
  if (state == GO_UP)
    game->isClick = false;
  else if (state == GO_DOWN)
    game->isClick = true;
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
  ef::Game game(port, 1000, 1000);

  bunny_set_loop_main_function(loop);
  bunny_set_key_response(key);
  bunny_set_click_response(click);
  bunny_set_display_function(display);
  bunny_loop(game.cam.getWin(), 60, &game);
}