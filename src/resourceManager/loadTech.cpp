#include "resourceManager.hh"
#include <iostream>

int ef::ResourceManager::LoadTech(bool reset)
{
  if(reset)
    allTech.clear();
  std::vector<std::string> conf = {"test.dabsic"};
  std::string stati = "resours/tech/conf/";
  if(allTech.size() == conf.size())
    return 0;
  int error;
  Tech tmp;
  std::string temp;
  for(unsigned int i = allTech.size(); i< conf.size(); i++)
    {
      temp = stati + conf[i];
      for(int tri = 0;tri < 10 && (error = tmp.load(temp)) != 0; tri ++)
	{
	  std::cout<<"try n°"<< tri <<" : " << " file ("<< stati<< conf[i]<<") ";
	  switch(error)
	    {
	    case 1:
	      std::cout << "the file is not here or can't load\n";
	      break;
	    case 2:
	      std::cout << "fail Name\n";
	      break;
	    case 3:
	      std::cout << "fail isSearched\n";
	      break;
	    case 4:
	      std::cout << "fail timeToProduce\n";
	      break;
	    case 5:
	      std::cout << "fail cost\n";
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
	  allTech.push_back(tmp);
	}
    }
  return -1;
}
