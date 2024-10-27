#include "../include/pion.hpp"


Pion::Pion(int x ,int y , int c):Piece(x,y,c){
  this->depart = x;
}

bool Pion::is_valide(int nx ,int ny ,const Echiquier & x) const{
  int direction = (depart == 1)? 1:-1;
  if (nx > 7 || nx < 0 || ny > 7 || ny < 0)return false;
  if (x.getCol(nx,ny) == getColor())return false;

  if (ny == gety()) {
    if (nx == getx() + 2 * direction) {
      if (getx() != depart || x.getCol(getx() + direction, gety()) != 0 || x.getCol(nx, ny) != 0) return false;
    } else if (nx != getx() + direction || x.getCol(nx, ny) != 0) return false;
  } else if (ny == gety() + 1 || ny == gety() - 1) {
    if (nx != getx() + direction || x.getCol(nx, ny) == 0 || x.getCol(nx, ny) == getColor()) {
        return false;
    } 
  } else return false;

  
  return true;
}

void Pion::print()const{
  std::string c = "\e[38;5;"+std::to_string( Piece::color)+"m";
  std::string back = "\e[48;5;";
  
  if ((Piece::x + Piece::y)%2 == 0){
    back.append("255m");
  }else{
    back.append("0m");
  }

  std::cout <<back<<c<<"\u265F "<<"\e[0m";

}
bool Pion::promotion() const{
  if (getx() == 7 || getx() ==0){
    return true;
  }
  return false;
}