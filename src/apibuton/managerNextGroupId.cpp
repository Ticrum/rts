#include "apiButton.hh"

unsigned int ef::ButonManager::nextGroupId()
{
  unsigned int max = 0;
  for(unsigned int i = 0; i < groupIds.size(); i++)
    if(max < groupIds[i])
      max = groupIds[i];
  return max + 1;
}
