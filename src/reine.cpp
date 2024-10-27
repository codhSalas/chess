#include "../include/reine.hpp"


Reine::Reine(int x ,int y , int c):Piece(x,y,c){}


bool Reine::is_valide(int nx ,int ny ,const Echiquier & x) const{
  if (nx > 7 || nx < 0 || ny > 7 || ny < 0)return false;
  if (x.getCol(nx,ny) == getColor())return false;
  
  bool a =(nx == getx()) ? true :false;
  bool b =(ny == gety()) ? true :false;
  
  if (a != b){
    return true;
  }
    int dx = abs(getx() - nx);
    int dy = abs(gety() - ny);
    if (dx != dy) 
        return false;
    
    // Détermination de la direction
    int mx = (nx > getx()) ? 1 : -1;
    int my = (ny > gety()) ? 1 : -1;
    
    // Vérification du chemin
    int currentX = getx() + mx;
    int currentY = gety() + my;
    
    while (currentX != nx && currentY != ny) {
      if (x.getCol(currentX, currentY) != 0) {
          return false;  
      }
      currentX += mx;
      currentY += my;
    }
    
  return true;
}
void Reine::print() const{
  std::string c = "\e[38;5;"+std::to_string( Piece::color)+"m";
  std::string back = "\e[48;5;";
  
  if ((Piece::x + Piece::y)%2 == 0){
    back.append("255m");
  }else{
    back.append("0m");
  }

  std::cout <<back<<c<<"\u265B "<<"\e[0m";

}