#include "../include/cavalier.hpp"


Cavalier::Cavalier(int x ,int y , int c):Piece(x,y,c){}

bool Cavalier::is_valide(int nx ,int ny ,const Echiquier& x)const {
  if (nx > 7 || nx < 0 || ny > 7 || ny < 0)return false;
  if (x.getCol(nx,ny) == getColor())return false;
  int dx = abs(Piece::x -nx);
  int dy = abs(Piece::y -ny);
  
  
  if(!((dx == 2 && dy == 1)||(dx == 1 && dy == 2))) return false;
  return true;
}
void Cavalier::print() const{
  std::string c = "\e[38;5;"+std::to_string( Piece::color)+"m";
  std::string back = "\e[48;5;";
  
  if ((Piece::x + Piece::y)%2 == 0){
    back.append("255m");
  }else{
    back.append("0m");
  }

  std::cout <<back<<c<<"\u265E "<<"\e[0m";

}