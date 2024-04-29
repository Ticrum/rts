// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 22/04/2024 15:50:46 ******************************************************
// romain.piccoche <romain.picoche@laika.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "apiButton.hh"
#include <iostream>

static void text(std::string cmd)
{
  std::cout << "$> " << cmd << "\n";
}

int main ()
{
  ef::ButonManager manage;
  t_bunny_accurate_area square;
  std::shared_ptr<ef::Bpixelarray> ero (new ef::Bpixelarray());
  while(ero->Init("resours/sprit/error.png"));
  square.x = 0;
  square.y = 70;
  square.w = 40;
  square.h = 40;
  std::shared_ptr<ef::Bpixelarray> px (new ef::Bpixelarray());
  manage.add(1, true, square, BLACK, WHITE, px, "je suis", text, false);
  square.x = 0;
  square.y = 0;
  square.w = 40;
  square.h = 40;
  manage.add(0, true, square, BLACK, WHITE, px, "___-___", text, false);
  square.x = 70;
  square.y = 0;
  square.w = 40;
  square.h = 40;
  manage.add(1, true, square, BLACK, WHITE, ero, "SUIS JE", text, false);
  square.x = 70;
  square.y = 70;
  square.w = 40;
  square.h = 40;
  manage.add(2, true, square, BLACK, WHITE, ero, "heinqui", text, false);
  manage.printTerminal();
  t_bunny_window *win;
  std::shared_ptr<ef::Bpixelarray> screen (new ef::Bpixelarray());
  
  win = bunny_start(500,500, false, "test_blit");
  while(screen->Init(500, 500));
  screen->Clear(PINK);
  manage.print(screen);

  bunny_blit(&win->buffer, screen->GetClip(), NULL);
  bunny_display(win);
  sleep(5);
  ef::Pos click(10);
  std::cout << click.x<<", "<< click.y<< "\n";
  manage.checkClick(click);
  click.x += 70;
  std::cout << click.x<<", "<< click.y<< "\n";
  manage.checkClick(click);
  click.y += 70;
  std::cout << click.x<<", "<< click.y<< "\n";
  manage.checkClick(click);
  click.x -= 70;
  std::cout << click.x<<", "<< click.y<< "\n";
  manage.checkClick(click);
  manage.hideAll();
  screen->Clear(PINK);
  manage.print(screen);
  bunny_blit(&win->buffer, screen->GetClip(), NULL);
  bunny_display(win);
  sleep(1);
  manage.showAll();
  screen->Clear(PINK);
  manage.print(screen);
  bunny_blit(&win->buffer, screen->GetClip(), NULL);
  bunny_display(win);
  sleep(1);
  manage.hide(1);
  screen->Clear(PINK);
  manage.print(screen);
  bunny_blit(&win->buffer, screen->GetClip(), NULL);
  bunny_display(win);
  sleep(1);
  manage.show(1);
  screen->Clear(PINK);
  manage.print(screen);
  bunny_blit(&win->buffer, screen->GetClip(), NULL);
  bunny_display(win);
  sleep(1);
  manage.hide(1,1);
  screen->Clear(PINK);
  manage.print(screen);
  bunny_blit(&win->buffer, screen->GetClip(), NULL);
  bunny_display(win);
  sleep(1);
  manage.show(1,1);
  screen->Clear(PINK);
  manage.print(screen);
  bunny_blit(&win->buffer, screen->GetClip(), NULL);
  bunny_display(win);
  sleep(1);
  manage.hide(1,0);
  screen->Clear(PINK);
  manage.print(screen);
  bunny_blit(&win->buffer, screen->GetClip(), NULL);
  bunny_display(win);
  sleep(1);
  manage.show(1,0);
  screen->Clear(PINK);
  manage.print(screen);
  bunny_blit(&win->buffer, screen->GetClip(), NULL);
  bunny_display(win);
  sleep(1);

  //  manage.pop(1, 1);
  //manage.printTerminal();
}
