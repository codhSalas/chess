#include "./include/jeu.hpp"
int main(){
  // Jeu x =Jeu();
  // x.player_mov();
  Echiquier z =Echiquier(1);
  z.print();
  z.mouve(6,6,4,6);
  z.print();
  z.mouve(4,6,3,6);
  z.print();
  z.mouve(3,6,2,6);
  z.print();
  z.mouve(2,6,1,6);
  z.print();
  z.mouve(1,6,0,6);
  z.print();
  // z.mouve(0,1,0,0);
}