#ifndef __BPIXELARRAY_HH__
#define __BPIXELARRAY_HH__

#include <string>
#include <memory>
#include <lapin.h>
#include "object.hh"

namespace ef
{
  class Bpixelarray
  {
  public:
    Bpixelarray();
    ~Bpixelarray();
    void Clear(unsigned int color);
    bool Init(unsigned int width,
	      unsigned int height);
    bool Init(std::string file);
    unsigned int &GetSetPixel(unsigned int pos);
    unsigned int &GetSetPixel(unsigned int x,
			      unsigned int y);
    void placePixel(Pos &pos,
		    unsigned int colo);
    void Blit(Bpixelarray &other,
	      Pos const &start,
	      AcuPos const &size);
    void Blit(Bpixelarray &other,
	      Pos const &start,
	      AcuPos const &size,
	      int alegence);
    t_bunny_clipable *GetClip()const;
    Pos GetSize();
  private:
    t_bunny_pixelarray *px;
    std::unique_ptr<unsigned int[]> pixels;
  };
};//!ef

#endif//__BPIXELARRAY_HH__
