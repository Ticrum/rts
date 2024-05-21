#include "map.hh"
#include <iostream>

int main()
{
  std::cout<<"map start"<< std::endl;
  std::string file("map1.dab");
  ef::Map tr(file);
  tr.print();
  std::cout<<"map end"<< std::endl;
}
