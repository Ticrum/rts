#include "apiButton.hh"

void ef::ButonManager::changePx(unsigned int groupp,
				unsigned int id,
				std::shared_ptr<ef::Bpixelarray> &px)
{
  if(group.count(groupp) != 0)
    {
      ef::Groupe ind = group[groupp];
      unsigned int max = ind.buton.size();
      for(unsigned int i = 0; i < max; ++i)
	{
	  if(ind.buton[i].id == id)
	    ind.buton[i].sprit = px;
	}
    }
}
