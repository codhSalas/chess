#ifndef PION
#define PION
#include "piece.hpp"
#include "echiquier.hpp"

class Pion : public Piece{
private:
  int depart;
public:
  Pion(int x , int y , int c);
  bool is_valide(int nx ,int ny ,const Echiquier & x) const override;
  void print() const override ;
  bool promotion() const override;


};
 

#endif