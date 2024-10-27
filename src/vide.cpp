#include "../include/vide.hpp"
Vide::Vide(int xi,int yi):Piece(xi,yi,0){}
void Vide::print() const{
  if ((Piece::x + Piece::y)%2 == 0){
    std::cout <<"\e[48;5;255m"<<"  "<<"\e[0m";
  }else{
     std::cout <<"\e[48;5;0m"<<"  "<<"\e[0m";
  }
}