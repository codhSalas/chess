#ifndef PIECE
#define PIECE
#include <iostream>
#include <string>
#include <cmath>
class Echiquier;
class Piece{
protected:
  int x,y,color;
public:
  Piece(int a, int b ,int c);
  virtual ~Piece() {}
  virtual bool is_valide(int nx ,int ny , const Echiquier & x)const ;
  virtual void print() const ;
  void mouve (int x, int y);
  int getColor() const;
  int getx() const;
  int gety() const;

};


#endif