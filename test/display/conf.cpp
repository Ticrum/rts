#include "resourceManager.hh"
#include "unit.hh"
#include "Bpixelarray.hh"
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
  std::cout<< "\nUNIT\n" <<(rsa.getUnit("missingno")<< "");
  std::cout<< "\nBUILT\n" <<(rsa.getBuild("LATHOURES")<< "");
  std::cout<< "\nSHOT\n" <<(rsa.getShot("test")<< "");
  std::cout<< "\nTECH\n" <<(rsa.getTech("test")<< "");
  std::string po("");
  std::vector<ef::ConfWeapon> &weaps = rsa.getWeaponConf();
  for(unsigned int i = 0; i< weaps.size(); i++)
    po += (weaps[i] << "\n");
  std::cout<<"\nWEAP\n"<< po;
  ef::Pos pos;
  ef::ConfUnit confuni = rsa.getUnit("missingno");
  pos.x = 0;
  pos.y = 1;
  confuni.objSize.y = 2;
  ef::Unit uni(confuni, rsa.getSprit()[confuni.img], pos, 0, 1140811007, rsa.getWeaponConf());
  std::cout <<"x "<< uni.getPos().x<< " y " << uni.getPos().y << "\n";
  t_bunny_window *win;
  win = bunny_start(500,500, false, "test_blit");
  ef::Bpixelarray px;
  pos.x = 100;
  pos.y = 100;
  ef::AcuPos cam;
  cam.x = 0;
  cam.y = 0;
  while(px.Init(500, 500));
  //uni.UnitDisplay(px, , cam);
  pos.x = 1;
  pos.y = 1;
  confuni.objSize.y = 1;
  ef::Unit nit(confuni, rsa.getSprit()[confuni.img], pos, 0, 1140811007, rsa.getWeaponConf());
  std::cout <<"x "<< nit.getPos().x<< " y " << nit.getPos().y << "\n";
  pos.x = 100;
  pos.y = 100;
  //  nit.Display(px, pos, cam);
  bunny_blit(&win->buffer, px.GetClip(), NULL);
  bunny_display(win);
  sleep(10);
  return 0;
}
