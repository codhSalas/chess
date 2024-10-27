#include "../include/roi.hpp"


Roi::Roi(int nx ,int ny , int c):Piece(nx,ny,c){}
bool Roi::is_valide(int nx ,int ny ,const Echiquier & x) const{
  if (nx > 7 || nx < 0 || ny > 7 || ny < 0)return false; 
  if (x.getCol(nx,ny) == getColor())       return false; 
  if ((nx > getx()+1) || (nx < getx()-1))  return false;
  if ((ny > gety()+1) || (ny < gety()-1))  return false;
  

  return true;
}
void Roi::print() const{
  std::string c = "\e[38;5;"+std::to_string( Piece::color)+"m";
  std::string back = "\e[48;5;";
  
  if ((Piece::x + Piece::y)%2 == 0){
    back.append("255m");
  }else{
    back.append("0m");
  }

  std::cout <<back<<c<<"\u265A "<<"\e[0m";

}