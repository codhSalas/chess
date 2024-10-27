#ifndef REINE
#define REINE

#include "piece.hpp"
#include "echiquier.hpp"
class Reine : public Piece{
private:
  
public:
  Reine(int x , int y , int c);
  bool is_valide(int nx ,int ny ,const Echiquier & x) const override;
  void print() const override;
};


#endif