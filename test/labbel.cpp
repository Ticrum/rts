// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 23/05/2024 18:19:01 ******************************************************
// romain.piccoche <romain.picoche@laika.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************
#include "apiButton.hh"

int main()
{
  ef::ButonManager manager;
  std::shared_ptr<ef::Bpixelarray> img = std::make_shared<ef::Bpixelarray>();
  ef::Bpixelarray px;
  t_bunny_window *win = bunny_start(1000,1000, false, "labbel\n");
  for(int i = 0; i< 10 && img->Init("resours/sprit/font.png"); ++i);
  for(int i = 0; i< 10 && px.Init(1000,1000); ++i);
  if(img->GetClip() == NULL || px.GetClip() == NULL||win == NULL)
    return 1;
  manager.printTerminal();
  ef::AcuPos size(1);
  manager.add(ef::Pos(600), size,"Juste to check if the character limit is working, so was your day? Mine was prety boring, i have got a lot of useless stuff to do and my group don't understand the goal of this dam project. I'm realy suround by fucking morron", img);
  size.x = 1;
  size.y = 1;
  unsigned int tmp = manager.add(ef::Pos(20), size,"the heavy is dead", img);
  size.x = 2;
  size.y = 2;
  manager.add(ef::Pos(50), size, "MEDIC", img);
  px.Clear(BLACK);
  manager.print(px);
  manager.printTerminal();
  
  bunny_blit(&win->buffer, px.GetClip(), NULL);
  bunny_display(win);
  px.Clear(BLACK);
  bunny_usleep(5e6);
  
  manager.popLabbel(tmp);
  manager.print(px);
  manager.printTerminal();
  
  bunny_blit(&win->buffer, px.GetClip(), NULL);
  bunny_display(win);
  px.Clear(BLACK);
  bunny_usleep(5e6);
  
  size.x = 1;
  size.y = 1;
  manager.add(ef::Pos(500), size,"Jawoh!", img);
  manager.print(px);
  manager.printTerminal();
  
  bunny_blit(&win->buffer, px.GetClip(), NULL);
  bunny_display(win);
  px.Clear(BLACK);
  bunny_usleep(5e6);
  
  return 0;
}
