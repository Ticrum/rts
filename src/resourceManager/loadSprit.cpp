#include "resourceManager.hh"
#include "Bpixelarray.hh"
#include <iostream>

int ef::ResourceManager::LoadSprit(bool reset)
{
  if(reset)
    sprites.clear();
  std::vector<std::string> allConf = {"error.png", "errorunit.png", "FUCK.png", "barracks.jpg", "moneyprinter.jpg", "scout.jpg", "sniper.jpg", "soldier.jpg", "tower.jpg", "artillerie.jpg", "car.jpg", "factory.jpg", "tank.png", "rocket.jpg", "barbar.jpg"};
  std::string stati = "resours/sprit/";
  if(sprites.size() == allConf.size())
    return -2;
  std::string temp;
  bool exit;
  for(unsigned int i = sprites.size(); i < allConf.size(); i++)
    {
      std::shared_ptr<Bpixelarray> tmp = std::make_shared<Bpixelarray>();
      temp = stati + allConf[i];
      for(int tri = 0;tri < 10 && (exit = tmp->Init(temp)) != 0; tri ++)
	  std::cout<<"try n°"<< tri<<" : " << " file ("<< temp <<") ";
      if(exit)
	return i;
      else
	{
	  sprites[allConf[i]] = tmp;
	  std::cout << "load : " << temp<< "\n";
	}
    }
  return -1;
}
