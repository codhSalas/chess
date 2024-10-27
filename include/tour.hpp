#ifndef TOUR
#define TOUR
#include "piece.hpp"
#include "echiquier.hpp"
class Tour : public Piece{
private:
  
public:
  Tour(int x , int y , int c);
  bool is_valide(int nx ,int ny ,const Echiquier & x) const override ;
  void print() const override;
};


#endif