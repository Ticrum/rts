#include "apiButton.hh"

unsigned int ef::ButonManager::checkClick(Pos click,
					  Pos start,
					  double ratioCasePix)
{
  Pos min;
  Pos max;
  for(unsigned int i = 0; i < groupIds.size(); ++i)
    {
      if(group[groupIds[i]].Case)
	{
	  min.x = (group[groupIds[i]].min.x - start.x) * ratioCasePix;
	  min.y = (group[groupIds[i]].min.y - start.y) * ratioCasePix;
	  max.x = min.x + (group[groupIds[i]].max.x - start.x) * ratioCasePix;
	  max.y = min.y + (group[groupIds[i]].max.y - start.y) * ratioCasePix;
	}
      else
	{
	  min.x = group[groupIds[i]].min.x;
	  min.y = group[groupIds[i]].min.y;
	  max.x = min.x + group[groupIds[i]].max.x;
	  max.y = min.x + group[groupIds[i]].max.y;
	}
      if(min.x <= click.x && min.y <= click.y &&
	 max.x >= click.x && max.y >= click.y)
	{
	  Groupe grp = group[groupIds[i]];
	  unsigned int chariot = 0;
	  while(chariot < grp.buton.size())
	    {
	      if(grp.Case)
		{
		  min.x = (grp.buton[chariot].square.x - start.x) * ratioCasePix;
		  min.y = (grp.buton[chariot].square.y - start.y) * ratioCasePix;
		  max.x = min.x + grp.buton[chariot].square.w * ratioCasePix;
		  max.y = min.y + grp.buton[chariot].square.h * ratioCasePix;
		}
	      else
		{
		  min.x = grp.buton[chariot].square.x;
		  min.y = grp.buton[chariot].square.y;
		  max.x = min.x + grp.buton[chariot].square.w;
		  max.y = min.y + grp.buton[chariot].square.h;
		}
	      if(min.x <= click.x && min.y <= click.y &&
		 max.x >= click.x && max.y >= click.y)
		{
		  grp.buton[chariot].action(grp.buton[chariot].command);
		  return 0;
		}
	      chariot ++;
	    }
	}
    }
  return 1;
}
