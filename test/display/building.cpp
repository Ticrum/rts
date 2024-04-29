#include "resourceManager.hh"
#include "apiButton.hh"
#include <iostream>
int main()
{
  std::shared_ptr<ef::Bpixelarray> screen (new ef::Bpixelarray());
  while(screen->Init(500, 500));
  ef::ResourceManager resource;
  ef::ButonManager butons;
  std::cout << "build: " << resource.LoadBuild() << std::endl;
  std::cout << " wep : " << resource.LoadWeapon() << std::endl;
  screen->Clear(PINK);
  manage.print(screen);
  bunny_blit(&win->buffer, screen->GetClip(), NULL);
  bunny_display(win);
  sleep(5);
}
