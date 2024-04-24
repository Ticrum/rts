#include "apiButton.hh"
#include <iostream>
void ef::ButonManager::printTerminal()
{
  std::string tmp;
  std::cout<<"\n\nSTART OF THE APIBUTON LOG\n";
  for(unsigned int i = 0; i < groupIds.size(); ++i)
    {
      tmp = group[groupIds[i]] << "";
      std::cout << groupIds[i] << ": \n" << tmp ;
    }
  std::cout<<"\n\nEND OF THE APIBUTON LOG\n\n";
}
