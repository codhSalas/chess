#ifndef ROI
#define ROI
#include "piece.hpp"
#include "echiquier.hpp"
class Roi : public Piece{
private:
  
public:
  Roi(int x , int y , int c);
  bool is_valide(int nx ,int ny ,const Echiquier & x) const override;
  void print() const override;
};


#endif