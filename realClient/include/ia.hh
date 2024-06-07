#ifndef __IA_HH__
#define __IA_HH__

#include <vector>
#include <string>
#include "../../include/clientPlayerInfo.hh"

namespace ef
{
  struct Game;

  enum TypeVision
    {
      DIRECT,
      INDIRECT
    };

  enum ActionType
    {
      POKE,
      ATTACK,
      ALLIN,
      PROTECT_FROM_DIST,
      PROTECT,
      PROTECT_AT_ALL_COST,
      RETREAT,
      FLEE,
      ALLOUT_FLEE
    };

  enum Dist
    {
      FAR,
      MID,
      CLOSE,
      ONIT
    };

  struct Task
  {
    Task(TypeVision _visType, std::string _target, Dist _dist, double _priority, double _pressure, bool _isPlayer, bool _isEnemy);
    Task(Task const & other);
    Task & operator=(Task const & other);

    TypeVision visType;
    std::string target;
    Dist dist;
    double priority;
    double pressure[60];
    bool isPlayer;
    bool isEnemy;
  };

  struct Action
  {
    std::string target;
    ActionType actType;
  };

  class Brain
  {
  public:
    Brain(double _playerAtracted, double _agressive, double _teamPlayer, double _protecting);
    void targetInVision(std::string target, Dist dist, double priority, double pressure, bool isPlayer, bool isEnemy);
    void targetOutVision(std::string target, bool isEnemy);
    void targetDied(std::string target, bool isEnemy);
    void targetFastCheck(std::string target, Dist dist, double priority, double pressure, bool isPlayer, bool isEnemy);
    void updatePressure(std::string target, double newPressure, bool isEnemy);
    void updatePriority(std::string target, double newPrio, bool isEnemy);
    void updateDist(std::string target, Dist newDist, bool isEnemy);
    std::vector<Action> getActions(double timePassed);

  private:
    void avoidImediateDanger(std::vector<Action> & actions);
    void updatePressureTime(double timePassed);
    void decalPresure(Task & task);

    double playerAtracted;
    double agressive;
    double teamPlayer;
    double protecting;
    std::vector<Task> tasks;
    std::vector<Task> allyTasks;
  };

  class Ia
  {
  public:
    Ia(double playerAtracted, double agressive, double teamPlayer, double protecting, ClientPlayerInfo & _cli, std::function<void(std::string)> _singleCommand, Pos _size);
    void compute(double timePassed);
    void getMainBuild();

  private:
    void manageBuildProduction();
    void manageUnitProduction();
    void moveUnit();
    bool placeBuild();

    Brain brain;
    int nbrMoneyP;
    int nbrProd;
    int unitToProd;
    int internalEnergy;
    Pos mapSize;
    bool resourceFilled;
    Map pressureMap;
    ClientPlayerInfo & cli;
    Pos size;
    std::function<void(std::string)> singleCommand;
    std::vector<std::shared_ptr<Building>> MainBuild;
  };

};

#endif // __IA_HH__
