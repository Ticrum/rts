#include "resourceManager.hh"
#include <iostream>

int ef::ResourceManager::LoadBuild(bool reset)
{
  if(reset)
    buildingConf.clear();
  std::vector<std::string> conf = {"LATHOURES.dabsic"};
  std::string stati = "resours/building/conf/";
  if(buildingConf.size() == conf.size())
    return 0;
  int error;
  ConfBuilding tmp;
  std::string temp;
  for(unsigned int i = buildingConf.size(); i< conf.size(); i++)
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
	      std::cout << "fail buildCost\n";
	      break;
	    case 13:
	      std::cout << "fail buildTTP\n";
	      break;
	    case 14:
	      std::cout << "fail buildType\n";
	      break;
	    case 15:
	      std::cout << "fail buildCanBetarguet\n";
	      break;
	    case 16:
	      std::cout << "fail buildEnerCost\n";
	      break;
	    case 17:
	      std::cout << "fail buildEnerProd\n";
	      break;
	    case 18:
	      std::cout << "fail buildMoneProd\n";
	      break;
	    case 19:
	      std::cout << "fail buildweapConfSize\n";
	      break;
	    case 20:
	      std::cout << "fail build wrong typ(too high or negativ)e\n";
	      break;
	    default:
	      std::cout << "fail build n°"<< error << "\n";
	    }
	}
      if(error == 0)
	{
	  std::cout << "load : " << stati << conf[i]<< "\n";
	  buildingConf.push_back(tmp);
	}
      else
	return i;
    }
  return -1;
}
