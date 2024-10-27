#include "../include/tour.hpp"


Tour::Tour(int x ,int y , int c):Piece(x,y,c){}

bool Tour::is_valide(int nx ,int ny ,const Echiquier & x) const {
  if (nx > 7 || nx < 0 || ny > 7 || ny < 0)return false;
  if (x.getCol(nx,ny) == getColor())return false;
  
  bool a =(nx == getx());
  bool b =(ny == gety());
  if(a == b) return false;

  for (int i = getx(); i < nx; i++){
    if( x.getCol(i,gety()) != 0) return false;
  }
  for (int i = gety(); i < ny; i++){
    if( x.getCol(i,getx()) != 0) return false;
  }

  return true;
}

void Tour::print() const{
  std::string c = "\e[38;5;"+std::to_string( Piece::color)+"m";
  std::string back = "\e[48;5;";
  
  if ((Piece::x + Piece::y)%2 == 0){
    back.append("255m");
  }else{
    back.append("0m");
  }

  std::cout <<back<<c<<"\u265C "<<"\e[0m";

}