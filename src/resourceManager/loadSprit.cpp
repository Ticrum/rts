#include "resourceManager.hh"
#include "Bpixelarray.hh"
#include <iostream>

int ef::ResourceManager::LoadSprit(bool reset)
{
  if(reset)
    sprites.clear();
  std::vector<std::string> allConf = {};
  std::string stati = "resours/sprit/";
  if(sprites.size() == allConf.size())
    return 0;
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
