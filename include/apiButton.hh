// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 27/03/2024 11:04:55 ******************************************************
// romain.piccoche <romain.picoche@aldrin.efrits.fr>
// - rts -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#ifndef __APIBUTTON_HH__
#define __APIBUTTON_HH__

#include "Bpixelarray.hh"
#include <map>
#include <functional>

namespace ef
{
  struct Buton
  {
    Buton();
    Buton(Buton const& other);
    Buton(unsigned int _group,
	  unsigned int _id,
	  bool _print,
	  t_bunny_accurate_area _square,
	  unsigned int _outside,
	  unsigned int _background,
	  std::shared_ptr<ef::Bpixelarray> _px,
	  std::string _action,
	  std::function<void(std::string)> func);
    std::string operator<<(std::string src);
    Buton &operator=(Buton const& other);
    unsigned int group;
    unsigned int id;
    bool print;
    t_bunny_accurate_area square;
    t_bunny_color outside;
    t_bunny_color background;
    std::shared_ptr<ef::Bpixelarray> sprit;
    std::string command;
    std::function<void(std::string)> action;
  };//buton

  struct Groupe
  {
    Groupe();
    Groupe(Groupe const& other);
    std::string operator<<(std::string src);
    Groupe &operator=(Groupe const& other);
    unsigned int update(t_bunny_accurate_area square);
    void alowCase();
    void showAll();
    void hideAll();
    bool Case;
    unsigned int Id;
    AcuPos min;
    AcuPos max;
    std::vector<Buton> buton;
  };//!groupe

  class ButonManager
  {
  public:
    ButonManager();
    ~ButonManager();
    bool init(std::string file);
    Pos add(unsigned int groupp,
	    bool print,
	    t_bunny_accurate_area square,
	    unsigned int outside,
	    unsigned int background,
	    std::shared_ptr<ef::Bpixelarray> px,
	    std::string action,
	    std::function<void(std::string)> func,
	    bool Case);
    void pop(unsigned int groupp,
	     unsigned int id);
    void changePx(unsigned int groupp,
		  unsigned int id,
		  std::shared_ptr<ef::Bpixelarray> &px);
    unsigned int checkClick(Pos click,
			    Pos start = ef::Pos(0),
			    double ratioCasePix = 1);
    int show(unsigned int groupp);
    int show(unsigned int groupp,
	     unsigned int id);
    int hide(unsigned int groupp);
    int hide(unsigned int groupp,
	     unsigned int id);
    void showAll();
    void hideAll();
    void printTerminal();
    void print(std::shared_ptr<ef::Bpixelarray> px,
	       Pos start = ef::Pos(0),
	       double ratioCasePix = 1);
  private:
    std::vector<unsigned int> groupIds;
    std::map<unsigned int,ef::Groupe> group;
  };//butonManager
};//ef

#endif//__APIBUTTON_HH__
