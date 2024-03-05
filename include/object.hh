// EFRITS
// project:     rts
// created on:  2024-02-09 - 11:21 +0100
// 1st author:  thomas.barbe - thomas.barbe
// description: object header

#ifndef __OBJECT_HH__
#define __OBJECT_HH__

#include <vector>
#include <cstdint>
#include <string>
#include <memory>

namespace ef
{
  class Bpixelarray;
  struct Pos;
  struct ConformPos
  {
    Pos get();

    uint16_t x;
    uint16_t y;
  };

  struct Pos
  {
    ConformPos get();
    int isInRange(Pos other, int _x, int _y);

    int x;
    int y;
  };

  struct AcuPos
  {
    double x;
    double y;
  };

  struct ConfObj
  {
    ConfObj(std::string file);

    char conformConf[128];
    int imgId;
    Pos objSize;
    int maxhp;
    int armor;
    int rangeOfVision;
    int nbrDmg;
    int dmg;
    std::string conf;
  };

  class Object
  {
  public:
    Object(ConfObj _conf, Pos _pos, int _objId, int _alegence);
    Object(ConfObj _conf, Pos _pos, int _objId, int _alegence, int actualHp);
    void takeDmg(int _nbrDmg, int _dmg);
    Pos getPos();
    void setPos(int x, int y);
    int getId();
    int getImgId();
    Pos getObjSize();
    int getHp();
    int getArmor();
    int getRangeOfVision();
    int getAlegence();
    std::string getConf();
    void Display(Bpixelarray &px,
		 std::vector<Bpixelarray> &rsrc,
		 Pos caseSize);
    void kaboom(std::vector<std::shared_ptr<Object>> objects);

  protected:
    std::string conf;
    int objId;
    Pos pos;
    int imgId;
    Pos objSize;
    int hp;
    int maxhp;
    int armor;
    int rangeOfVision;
    int alegence;
    int nbrDmg;
    int dmg;
  };
}; // !ef

#endif // __OBJECT_HH__
