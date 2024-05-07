#include "resourceManager.hh"
#include <iostream>

int ef::ResourceManager::LoadShot(bool reset)
{
  if(reset)
    shot.clear();
  std::vector<std::string> conf = {"test.dabsic", "miniGunBullet.dab", "rifleBullet.dab", "pistolBullet.dab"};
  std::string stati = "resours/shot/conf/";
  if(shot.size() == conf.size())
    return -2;
  int error;
  ConfObj tmp;
  std::string temp;
  for(unsigned int i = shot.size(); i< conf.size(); i++)
    {
      temp = stati + conf[i];
      for(int tri = 0;tri < 10 && (error = tmp.LoadBasic(temp)) != 0; tri ++)
	{
	  std::cout<<"try n°"<< i<<" : " << " file ("<< stati<< conf[i]<<") ";
	  switch(error)
	    {
	    case 1:
	      std::cout << "the file is not here or can't load\n";
	      break;
	    case 2:
	      std::cout << "fail objName\n";
	      break;
	    case 3:
	      std::cout << "fail objName too big\n";
	      break;
	    case 4:
	      std::cout << "fail objImgId\n";
	      break;
	    case 5:
	      std::cout << "fail objSizeX\n";
	      break;
	    case 6:
	      std::cout << "fail objSizeY\n";
	      break;
	    case 7:
	      std::cout << "fail objMaxhp\n";
	      break;
	    case 8:
	      std::cout << "fail objArmor\n";
	      break;
	    case 9:
	      std::cout << "fail objRangeOfVision\n";
	      break;
	    case 10:
	      std::cout << "fail objNbrDmg\n";
	      break;
	    case 11:
	      std::cout << "fail objDmg\n";
	      break;
	    default:
	      break;
	    }
	}
      if(error != 0)
	return i;
      else
	{
	  std::cout << "load : " << stati << conf[i]<< "\n";
	  shot.push_back(tmp);
	}
    }
  return -1;
}
