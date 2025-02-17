// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 24/05/2024 12:17:16 ******************************************************
// romain.piccoche <romain.picoche@laika.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#include "apiButton.hh"
#include <iostream>
void ef::ButonManager::printTerminal()
{
  std::cout<<"\n\nSTART OF THE APIBUTON LOG\nstart of the buttons log"<< std::endl;
  for(unsigned int i = 0; i < groupIds.size(); ++i)
    std::cout << groupIds[i] << ": \n" << (group[groupIds[i]] << "");
  std::cout<<"end of the buttons log\n----------\nstart of the labbel log"<< std::endl;
  for(unsigned int i = 0; i < groupLabIds.size(); ++i)
    std::cout << groupLabIds[i] << ": " << (groupLab[groupLabIds[i]] << "");
  std::cout<<"end of the labbel log\n\nEND OF THE APIBUTON LOG\n"<< std::endl;
}
