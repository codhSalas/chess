#include "../include/echiquier.hpp"


#include "../include/vide.hpp"
#include "../include/cavalier.hpp"
#include "../include/fou.hpp"
#include "../include/pion.hpp"
#include "../include/reine.hpp"
#include "../include/roi.hpp"
#include "../include/tour.hpp"

Echiquier::Echiquier(){
  plateau[0][0] = new Tour(0,0,91);
  plateau[0][1] = new Cavalier(0,1,91);
  plateau[0][2] = new Fou(0,2,91);
  plateau[0][4] = new Roi(0,4,91);
   RoiNoir = plateau[0][4];
  plateau[0][3] = new Reine(0,3,91);
  plateau[0][5] = new Fou(0,5,91);
  plateau[0][6] = new Cavalier(0,6,91);
  plateau[0][7] = new Tour(0,7,91);
  
  for (int i = 0; i < 8; i++){
    plateau[1][i] = new Pion(1,i,91);
  }
  
  for (int i = 2; i < 8; i++){
    for (int j = 0; j < 8; j++){
      plateau[i][j] = new Vide(i,j);
    } 
  }
  for (int i = 0; i < 8; i++){
    plateau[6][i] = new Pion(6,i,31);
  }
  plateau[7][0] = new Tour(7,0,31);
  plateau[7][1] = new Cavalier(7,1,31);
  plateau[7][2] = new Fou(7,2,31);
  plateau[7][4] = new Roi(7,4,31);
  RoiBlanc =plateau[7][4];
  plateau[7][3] = new Reine(7,3,31);
  plateau[7][5] = new Fou(7,5,31);
  plateau[7][6] = new Cavalier(7,6,31);
  plateau[7][7] = new Tour(7,7,31);

}
Echiquier::~Echiquier(){
  // std::cout<<"je suis dans le destructeur\n";

  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      // std::cout<<i <<" "<<j <<"\n";
      delete plateau[i][j];
    }
  }
}
void Echiquier::print() const{
  std::cout<<"   A B C D E F G H  "<<std::endl;
  for (int i = 0; i < 8; i++){
    std::cout<<8-i<<" ";
    for (int j = 0; j < 8; j++){
      plateau[i][j]->print();
    }    
  std::cout<<" "<<8-i<<std::endl;
  }
  std::cout<<"   A B C D E F G H  "<<std::endl;
}

int Echiquier::getCol(int x, int y ) const{
  return plateau[x][y]->getColor();
}

bool Echiquier::mouve(int a , int b , int x ,int y){
  plateau[a][b]->print();
  std::cout << "\n";
  plateau[x][y]->print();
  std::cout << "\n";

  if(plateau[a][b]->is_valide(x,y,*this)){
    //arriver tempo
    Piece* temp = plateau[x][y];
    //je passe de ab vers xy
    plateau[x][y] = plateau[a][b];
    //je bouge dans les donner de la piece
    plateau[x][y]->mouve(x, y);
    //l'ancien je la mets a vide
    plateau[a][b] = new Vide(a, b);
    
      if (is_check(plateau[x][y]->getColor())) {
          delete plateau[a][b];  
          plateau[a][b] = plateau[x][y];   
          plateau[a][b]->mouve(a, b);     
          plateau[x][y] = temp;   
          std::cout << "Mouvement impossible : met le roi en échec" << std::endl;
          return false;
      }
      
      temp = nullptr;
      std::cout << "coup joué" << std::endl;
      return true;

  }else{
    std::cout << "coup interdis "<<std::endl;
    return false;
  }
  return true;
}
Echiquier::Echiquier(int i ){
  for (i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      plateau[i][j] = new Vide(i,j);    
    }
  }
  plateau[0][0] = new Roi(0,0,31);
  RoiBlanc =plateau[0][0];
  plateau[1][0] = new Reine(1,0,31);
  plateau[4][5] = new Reine(4,5,31);
  plateau[5][0] = new Roi(5,0,91);
  RoiNoir =plateau[5][0];
}


bool Echiquier::is_check (int col){
  int x,y;
  if (col ==31){
    x=RoiBlanc->getx();
    y=RoiBlanc->gety();
  }else if (col ==91){
    x=RoiNoir->getx();
    y=RoiNoir->gety();
  }
  
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      if (plateau[i][j]->is_valide(x,y,* this)){
        return true;
      }      
    }
  }
  return false;
}



bool Echiquier::is_checkMate(int col) {
    if (!is_check(col)) return false;

    int x, y;
    if (col == 31) {
        x = RoiBlanc->getx();
        y = RoiBlanc->gety();
    } else if (col == 91) {
        x = RoiNoir->getx();
        y = RoiNoir->gety();
    }

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int newX = x + dx;
            int newY = y + dy;

            // Vérifiez les limites du plateau
            if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
                if (plateau[x][y] != nullptr && plateau[x][y]->is_valide(newX, newY, *this)) {
                    Piece* temp = plateau[newX][newY];
                    plateau[newX][newY] = plateau[x][y];
                    plateau[newX][newY]->mouve(newX, newY);
                    plateau[x][y] = new Vide(x, y);

                    bool theCheck = is_check(col);
                    plateau[x][y] = plateau[newX][newY];
                    plateau[x][y]->mouve(x, y);
                    plateau[newX][newY] = temp;

                    temp = nullptr;

                    if (!theCheck) return false;
                }
            }

            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (plateau[i][j] != nullptr && plateau[i][j]->getColor() == col) {
                        if (plateau[i][j]->is_valide(newX, newY, *this)) {
                            Piece* temp = plateau[newX][newY];
                            plateau[newX][newY] = plateau[i][j];
                            plateau[newX][newY]->mouve(newX, newY);
                            plateau[i][j] = new Vide(i, j);

                            bool theCheck = is_check(col);
                            plateau[i][j] = plateau[newX][newY];
                            plateau[i][j]->mouve(i, j);
                            plateau[newX][newY] = temp;
                            temp = nullptr;
                            if (!theCheck) return false;
                        }
                    }
                }
            }
        }
    }
    if (col==31){
      std::cout<<"echec et mat pour les noirs\n";
    }else if(col==91){
      std::cout<<"echec et mat pour les blanc\n";
    }
    
    return true;
}
