#include "resourceManager.hh"
#include <iostream>

int ef::ResourceManager::LoadUnit(bool reset)
{
  if(reset)
    unitConf.clear();
  std::vector<std::string> conf = {"missingno.dabsic", "scout.dab", "baseSoldier.dab", "sniper.dab", "artillery.dab", "tank.dab", "car.dab", "rocketSoldier.dab", "barbar.dab", "helicopter.dab", "SC.dab", "rocketCopter.dab"};
  std::string stati = "resours/unit/conf/";
  if(unitConf.size() == conf.size())
    return -2;
  int error;
  ConfUnit tmp;
  std::string temp;
  for(unsigned int i = unitConf.size(); i< conf.size(); i++)
    {
      temp = stati + conf[i];
      for(int tri = 0;tri < 10 && (error = tmp.load(temp)) != 0; tri ++)
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
	    case 12:
	      std::cout << "fail UnitCost\n";
	      break;
	    case 13:
	      std::cout << "fail Unitspeeeeeeeeed\n";
	      break;
	    case 14:
	      std::cout << "fail Unit2FAST4U\n";
	      break;
	    case 15:
	      std::cout << "fail UnitmoveType\n";
	      break;
	    case 16:
	      std::cout << "fail UnitFly\n";
	      break;
	    case 17:
	      std::cout << "fail UnitTimeToProduce\n";
	      break;
	    case 18:
	      std::cout << "fail UnitweaponConfSize\n";
	      break;
	    case 19:
	      std::cout << "fail Unit Wrong Move type(too hight or negativ)\n";
	      break;
	    default:
	      std::cout << "fail unit weapon n°"<< error << "\n";
	    }
	}
      if(error == 0)
	{
	  std::cout << "load : " << stati << conf[i]<< "\n";
	  unitConf.push_back(tmp);
	}
      else
	return i;
    }
  return -1;
}
