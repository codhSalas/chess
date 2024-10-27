#ifndef CAVALIER
#define CAVALIER

#include "piece.hpp"
#include "echiquier.hpp"

class Cavalier : public Piece{
private:
  
public:
  Cavalier(int x , int y , int c);
  bool is_valide(int nx ,int ny , const Echiquier&  x)const override;
  void print() const override;
};


#endif