#include "game.hh"

#include <iostream>

static t_bunny_response loop(void *data)
{
  ef::Game *game = (ef::Game *)data;
  game->srv.computeActions(0.016);
  return GO_ON;
}

static t_bunny_response display(void *data)
{
  ef::Game *game = (ef::Game *)data;
  game->cam.display(game->srv);
  return GO_ON;
}

static t_bunny_response key(t_bunny_event_state state,
			    t_bunny_keysym sym,
			    void *data)
{
  if (state == GO_UP)
    return GO_ON;
  if (sym == BKS_ESCAPE)
    return EXIT_ON_SUCCESS;
  return GO_ON;
}

int main(void)
{
  ef::Game game(25300, 1000, 1000);

  bunny_set_loop_main_function(loop);
  bunny_set_key_response(key);
  bunny_set_display_function(display);
  bunny_loop(game.cam.getWin(), 60, &game);
}

