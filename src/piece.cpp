#include "../include/piece.hpp"

Piece::Piece(int a, int b ,int c):x(a),y(b),color(c){}
bool Piece::is_valide(int nx ,int ny , const Echiquier & x)const {return false;}
void Piece::print() const {}

int Piece::getColor() const {
  return this->color;
}

int Piece::getx() const {
  return this->x;
}

int Piece::gety() const {
  return this->y;
}
void Piece::mouve (int x, int y){
  this->x = x;
  this->y = y;
}