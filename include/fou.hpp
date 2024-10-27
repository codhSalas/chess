#ifndef FOU
#define FOU
#include "piece.hpp"
#include "echiquier.hpp"
class Fou : public Piece{  
public:
  Fou(int x , int y , int c);
  bool is_valide(int nx ,int ny ,const Echiquier & x) const override;
  void print()const override;
};


#endif