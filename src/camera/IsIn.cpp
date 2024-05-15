#include "Bpixelarray.hh"
#include "camera.hh"

bool ef::Camera::IsIn(ef::Pos start,
		      AcuPos caseSize,
                      std::shared_ptr<ef::Bpixelarray> &pic)
{
    AcuPos total;
    Pos end;
    end.x = caseSize.x + start.x;
    end.y = caseSize.y + start.y;
    Pos startPosCam;
    startPosCam.x = pos.x * zoom;
    startPosCam.y = pos.y * zoom;
    Pos finPosCam;
    finPosCam.x = startPosCam.x + size.x;
    finPosCam.y = startPosCam.y + size.y;

    if ((start.x > startPosCam.x && start.x < finPosCam.x &&
	 start.y > startPosCam.y && start.y < finPosCam.y) ||
	(end.x > startPosCam.x && end.x < finPosCam.x &&
	 end.y > startPosCam.y && end.y < finPosCam.y) ||
	(start.x > startPosCam.x && start.x < finPosCam.x &&
	 end.y > startPosCam.y && end.y < finPosCam.y) ||
	(end.x > startPosCam.x && end.x < finPosCam.x &&
	 start.y > startPosCam.y && start.y < finPosCam.y) ||
	(start.x < startPosCam.x && end.x > finPosCam.x &&
	 start.y < startPosCam.y && end.y > finPosCam.y) ||
	(start.x < startPosCam.x && end.x > finPosCam.x &&
	 ((start.y > startPosCam.y && start.y < finPosCam.y) || (end.y > startPosCam.y && end.y < finPosCam.y))) ||
	(start.y < startPosCam.y && end.y > finPosCam.y &&
	 ((start.x > startPosCam.x && start.x < finPosCam.x) || (end.x > startPosCam.x && end.x < finPosCam.x))))
      return true;
    return false;
}
