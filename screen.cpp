#include <iostream>
#include <vector>
#include <string>
#include "screen.h"
using namespace std;

Screen::Screen(int nlin, int ncol){
  this->nlin = nlin;
  this->ncol = ncol;
  // size_t nlinhasize = nlin;
  // size_t ncolsize = ncol;
  brush = 'a';
  vector< vector<char> > linhas(nlin);
  vector<char> linha(ncol);
  // mat.reserve(nlinha);
  for(int i=0; i<nlin; i++){
    linhas[i]=linha;
  }
  mat = linhas;
}

void Screen::iniciar(int nlin, int ncol){
  this->nlin = nlin;
  this->ncol = ncol;
  // size_t nlinhasize = nlin;
  // size_t ncolsize = ncol;
  brush = 'a';
  vector< vector<char> > linhas(nlin);
  vector<char> linha(ncol);
  // mat.reserve(nlinha);
  for(int i=0; i<nlin; i++){
    linhas[i]=linha;
  }
  mat = linhas;
}

Screen::Screen(){}

void Screen::setBrush(char brush){
  this->brush = brush;
}

void Screen::setPixel(int x, int y){
  mat[x][y] = brush;
}

void Screen::clear(){
  for(int i=0; i<nlin; i++){
    for(int j=0; j<ncol; j++){
      mat[i][j] = ' ';
    }
  }
}

print(Screen &t){
  for(int i=0; i<t.nlin; i++){
    for(int j=0; j<t.ncol; j++){
      cout << t.mat[i][j];
    }
    cout << endl;
  }
}

ostream& operator<<(ostream &os, Screen &t){
  string saida = "";
  for(int i=0; i<t.nlin; i++){
    for(int j=0; j<t.ncol; j++){
      saida+=t.mat[i][j];
    }
    saida+="\n";
  }
  os << saida;
}
// Matriz operator*(float a, const Matriz &m){
//   Matriz ret(m.nlin, m.ncol);
//   for(int i=0; i<m.nlin*m.ncol; i++){
//     ret.x[0][i] = a*m.x[0][i];
//   }
//   return(ret);
// }