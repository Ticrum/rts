#include "resourceManager.hh"
#include <iostream>

int ef::ResourceManager::LoadWeapon(bool reset)
{
  if(reset)
    weaponConf.clear();
  std::vector<std::string> conf = {"LEsTIK.dabsic", "miniGun.dabsic"};
  std::string stati = "resours/weapon/conf/";
  if(weaponConf.size() == conf.size())
    return -2;
  int error;
  ConfWeapon tmp;
  std::string temp;
  for(unsigned int i = weaponConf.size(); i< conf.size(); i++)
    {
      temp = stati + conf[i];
      for(int tri = 0;tri < 10 && (error = tmp.load(temp)) != 0; tri ++)
	{
	  std::cout<<"try n°"<< i<<" : " << " file ("<< stati<< conf[i]<<") ";
	  switch(error)
	    {
	    case 1:
	      std::cout<< "the file is not here or can't load \n";
	      break;
	    case 2:
	      std::cout<<"fails weapon\n";
	      break;
	    case 3:
	      std::cout<<"fail dmg\n";
	      break;
	    case 4:
	      std::cout<<"fail nbrAtt\n";
	      break;
	    case 5:
	      std::cout<<"fail cdr\n";
	      break;
	    case 6:
	      std::cout<<"fail range\n";
	      break;
	    case 7:
	      std::cout<<"target\n";
	      break;
	    default :
	      break;
	    }
	}
      if(error != 0)
	return i;
      else
	{
	  std::cout << "load : " << stati << conf[i]<< "\n";
	  weaponConf.push_back(tmp);
	}
    }
  return -1;
}
