#include "resourceManager.hh"
#include "apiButton.hh"
#include <iostream>

static void text(std::string cmd)
{
  std::cout << "$>  buton click'" << cmd << "'\n";
}

int main()
{
/*ef::Bpixelarray screen;
  while(screen.Init(1000, 1000));
  ef::ButonManager manage;
  ef::ResourceManager resource;
  t_bunny_window *win;
  win = bunny_start(1000,1000, false, "test_blit");
  std::cout << "build: " << resource.LoadBuild() << std::endl;
  std::cout << " wep : " << resource.LoadWeapon() << std::endl;
  resource.LoadSprit();
  std::string tmp = resource.getBuild("LATHOURES").butons;
  std::cout << tmp << std::endl;
  unsigned int start = 0;
  std::cout << ef::extract(start, tmp, ',')<< " _ " << start << std::endl;
  screen.Clear(PINK);
  ef::Pos pos(2);
  ef::Building buil(resource.getBuild("LATHOURES"), resource.getSprit()[resource.getBuild("LATHOURES").img], pos,1,1,resource.getWeaponConf());
  buil.Display(screen, ef::AcuPos(100));
  buil.DisplayHealth(screen, ef::AcuPos(100));
  ef::Pos size(1000);
  buil.displayButon(size, manage, text, resource.getSprit());
  manage.print(screen);
  manage.printTerminal();
  bunny_blit(&win->buffer, screen.GetClip(), NULL);
  bunny_display(win);
  ef::Pos click(110);
  std::cout << click.x<<", "<< click.y<< "\n";
  manage.checkClick(click);
  click.x = 90;
  click.y = 90;
  std::cout << click.x<<", "<< click.y<< "\n";
  manage.checkClick(click);
  sleep(5);
  screen.Clear(PINK);
  buil.removeButon(manage);
  manage.print(screen);
  manage.printTerminal();
  bunny_blit(&win->buffer, screen.GetClip(), NULL);
  bunny_display(win);
  std::cout << click.x<<", "<< click.y<< "\n";
  manage.checkClick(click);
  click.x = 90;
  click.y = 90;
  std::cout << click.x<<", "<< click.y<< "\n";
  manage.checkClick(click);
  sleep(5);
*/}

