// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 24/04/2024 15:16:03 ******************************************************
// romain.piccoche <romain.picoche@laika.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#ifndef __CAMERA_HH__
#define __CAMERA_HH__

#include "Bpixelarray.hh"
#include <string>
#include <functional>

namespace ef
{
  class ServerPlayersInfo;
  class ClientPlayerInfo;
  class Camera
  {
  public:
    Camera(int width,
	   int height,
	   bool serve);
    Camera(int width,
	   int height);
    int Init(std::string screen);
    bool IsIn(Pos start,
	      std::shared_ptr<ef::Bpixelarray> &pic);
    void ZoomIn(double add);
    double getZoom();
    void ZoomOut(double sub);
    void Move(AcuPos move);
    AcuPos getPos();
    void display(ClientPlayerInfo &cli);
    void display(ServerPlayersInfo &srv);
    t_bunny_window *getWin();
    t_bunny_position getMousePos();
    void drawSquareSelect(Pos start, Pos end);
  private:
    t_bunny_window *win;
    Bpixelarray game;
    Bpixelarray Hud;
    double zoom;
    AcuPos pos;
    bool god;
    Pos size;
    Pos mapSize;
  };//!Camera
};//!ef

#endif//__CAMERA_HH__
