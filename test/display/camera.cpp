#include "camera.hh"
#include "playerInfo.hh"
#include "resourceManager.hh"
#include <iostream>
int main()
{
  ef::ResourceManager rsa;
  int error = rsa.LoadUnit();
  std::cout<< "LoadUnit "<<error<<"\n";
  error = rsa.LoadBuild();
  std::cout<< "LoadBuild "<<error<<"\n";
  error = rsa.LoadTech();
  std::cout<< "LoadTech "<<error<<"\n";
  error = rsa.LoadWeapon();
  std::cout<< "LoadWeapon "<<error<<"\n";
  error = rsa.LoadShot();
  std::cout<< "LoadShot "<<error<<"\n";
  error = rsa.LoadSprit();
  std::cout<< "LoadSprit "<<error<<"\n";
  ef::PlayerInfo plt(rsa, 6584589, true);
  ef::ConfBuilding buil = rsa.getBuild("LATHOURES");
  std::map<std::string, std::shared_ptr<ef::Bpixelarray>> sprits = rsa.getSprit();
  std::cout<< "in " << buil.img <<" ?" << sprits.count(buil.img)<<"\n";
  ef::Pos place = (sprits[buil.img])->GetSize();
  std::cout<< place.x << " | | " << place.y<<"\n";
  place.x = 1;
  place.y = 1;
  plt.placeBuilding(make_shared<ef::Building>(buil, sprits[buil.img], place, 1, 0, rsa.getWeaponConf()));
  place.x = 3;
  place.y = 1;
  plt.placeBuilding(make_shared<ef::Building>(buil, sprits[buil.img], place, 1, 1, rsa.getWeaponConf()));
  place.x = 3;
  place.y = 0;
  plt.placeBuilding(make_shared<ef::Building>(buil, sprits[buil.img], place, 1, 0, rsa.getWeaponConf()));
  place.x = 1;
  place.y = 0;
  plt.placeBuilding(make_shared<ef::Building>(buil, sprits[buil.img], place, 1, 1, rsa.getWeaponConf()));
                          
  t_bunny_window *win;
  win = bunny_start(500,500, false, "BUNNY player");
  ef::Camera cam(500,500);
  bool gate = true;
  bunny_set_maximum_ram(1024 * 1024 * 500);
  bunny_set_error_descriptor(2);
  for(char a = 0; a < 10 && (gate = cam.Init("camera test")) != 0; a++){}
  if(gate != 0)
    {
      std::cout<<"Zut "<< gate<<"\n";
      return 1;
    }
  ef::Bpixelarray px;
  while(px.Init(500, 500));
  px.Clear(BLACK);
  cam.ZoomIn(10);
  plt.Display(px, cam, true);
  bunny_blit(&win->buffer, px.GetClip(), NULL);
  bunny_display(win);
  std::cout<< "\ndid u\n";
  std::cout<< "\nsee ?\n";
  sleep(5);
  cam.display(plt);
  sleep(5);
  return 0;
}
