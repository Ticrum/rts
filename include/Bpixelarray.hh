// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 22/04/2024 15:50:27 ******************************************************
// romain.piccoche <romain.picoche@laika.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#ifndef __BPIXELARRAY_HH__
#define __BPIXELARRAY_HH__

#include <string>
#include <memory>
#include <lapin.h>
#include "object.hh"

namespace ef
{
  struct Vertex
  {
    t_bunny_accurate_position pos;
    t_bunny_position tex;
    unsigned int color;
  };

  template <int Len>
  struct VertexArray
  {
    size_t length;
    Vertex vertex[Len];
  };


  class Bpixelarray
  {
  public:
    Bpixelarray(const Bpixelarray &) = delete;
    Bpixelarray();
    ~Bpixelarray();
    void Clear(unsigned int color);
    bool Init(unsigned int width,
	      unsigned int height);
    bool Init(std::string file);
    //unsigned int &GetSetPixel(unsigned int pos);
    //unsigned int &GetSetPixel(unsigned int x,
    //			      unsigned int y);
    void placePixel(Pos &pos,
		    unsigned int colo);
    void Blit(Bpixelarray &other,
	      AcuPos const &start,
	      AcuPos const &size);
    void Blit(Bpixelarray &other,
	      Pos const &start,
	      AcuPos const &size,
	      int alegence);
    t_bunny_clipable *GetClip()const;
    Pos GetSize();
    void rectangle(AcuPos &start,
		   AcuPos &size,
		   unsigned int background,
		   unsigned int outline);

    VertexArray<45000> recVec;
    VertexArray<5000> lineVec;
    VertexArray<20000> pixVec;

  private:
    //t_bunny_pixelarray *px;
    t_bunny_picture *px; // for GPU compute
    std::unique_ptr<unsigned int[]> pixels;
  };
};//!ef

#endif//__BPIXELARRAY_HH__
