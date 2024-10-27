#ifndef ECHIQUIER
#define ECHIQUIER
#include "piece.hpp"

class Echiquier {  
private:
  Piece *plateau [8][8];
  Piece *RoiNoir;
  Piece *RoiBlanc;
public:
  Echiquier();
  Echiquier(int i);

  ~Echiquier();
  void print() const;
  int getCol(int x, int y)const;
  bool mouve(int a , int b , int x ,int y);
  bool is_check(int col);
  bool is_checkMate(int col);

  
};
#endif