#ifndef __CAMERA_HH__
#define __CAMERA_HH__

#include "Bpixelarray.hh"
#include <string>

namespace ef
{
  class PlayerInfo;
  class ServerPlayersInfo;
  class Camera
  {
  public:
    Camera(int width,
	   int height,
	   bool serve);
    Camera(int width,
	   int height);
    int Init(std::string screen);
    bool IsIn(Pos &start,
	      std::shared_ptr<ef::Bpixelarray> &pic);
    void ZoomIn(double add);
    double getZoom();
    void ZoomOut(double sub);
    void Move(AcuPos move);
    void display(PlayerInfo &plr);
    void display(ServerPlayersInfo &srv);
  private:
    t_bunny_window *win;
    Bpixelarray game;
    Bpixelarray Hud;
    double zoom;
    AcuPos pos;
    bool god;
    Pos size;
  };//!Camera
};//!ef

#endif//__CAMERA_HH__
