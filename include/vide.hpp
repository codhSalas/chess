#ifndef VIDE
#define VIDE
#include "./piece.hpp"
#include "./echiquier.hpp"

class Vide : public Piece {
public:
  Vide(int xi, int yi);
  bool is_valide(int nx ,int ny ,const Echiquier & x) const override {return false;}
  void print() const override;
};


#endif