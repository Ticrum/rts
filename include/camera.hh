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
        bool Init(std::string screen);
        bool IsIn(Pos &start,
                  std::shared_ptr<ef::Bpixelarray> &pic);
        void ZoomIn(double add);
        void ZoomOut(double sub);
        void Move(AcuPos move);
        void display(PlayerInfo &plr,
                     std::vector<std::shared_ptr<ef::Bpixelarray>> &rsrc);
        void display(ServerPlayersInfo &srv,
                     std::vector<std::shared_ptr<ef::Bpixelarray>> &rsrc);
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
