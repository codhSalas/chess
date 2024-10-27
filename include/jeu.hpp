#ifndef JEU
#define JEU
#include "echiquier.hpp"

class Jeu{
private:
  Echiquier x;
  bool current;
public:
  Jeu();
  void print();
  bool player_mov();
};


#endif