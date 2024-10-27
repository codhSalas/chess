#include "../include/jeu.hpp"

Jeu::Jeu (){
  current =true;
}
void Jeu::print(){
  x.print();
}
bool Jeu::player_mov(){
  while (!(x.is_checkMate(91) || x.is_checkMate(31))){
    x.print();
    std::string currentPlay;
    std::cout <<"prochain coup ";
    std::cin >> currentPlay;
    std::cout <<"taille = "<<currentPlay.size()<<std::endl;

    if (currentPlay.size()>=4){
      int cury = currentPlay[0]-'a';
      int curx = 7-(currentPlay[1]-'1');
      int futy = currentPlay[2]-'a';
      int futx = 7-(currentPlay[3]-'1');
      
      std::cout<< "x= "<<curx<<" y= "<<cury<<" fx= "<<futx<<" fy "<<futy<<"\ncol = "<<x.getCol(curx,cury)<<std::endl;
      
      if (x.getCol(curx,cury) == 31 && current){
        if (x.mouve(curx,cury,futx,futy)){
          std::cout<<"coup valide pour les blanc\n";
          current = !current;
        }
      }else if(x.getCol(curx,cury) == 91 && !current){
        if (x.mouve(curx,cury,futx,futy)){
          std::cout<<"coup valide pour les noire\n";
          current = !current;
        }
      }else{
        std::cout<<"coup interdit\n";
      } 
    }else std::cout << "coup invalide\n";
  }

  return true;
}

