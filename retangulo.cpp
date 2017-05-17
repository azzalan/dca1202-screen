#include <vector>
#include <iostream>
#include "retangulo.h"
using namespace std;

Retangulo::Retangulo(int x, int y, int largura, int altura){
  setOrigem(x, y);
  vector< vector<bool> > linhas(altura);
  vector<bool> linha(largura);
  int tamX = largura;
  int tamY = altura;
  for(int i=0; i<tamY; i++){
    linhas[i] = linha;
  }
  for(int i=0; i<tamY; i++){
    if(i==0||i==tamY-1) {
      for(int j=0; j<tamX; j++){
        linhas[i][j] = true;
      }
    }
    else {
      linhas[i][0] = true;
      linhas[i][tamX-1] = true;
    }
  }
  setForma(linhas);
}

void Retangulo::draw(Screen &t){
  vector< vector<bool> > formax = getForma();
  for(int i=0; i<formax.size(); i++){
    for(int j=0; j<formax[i].size(); j++){
      if(formax[i][j]) t.setPixel(i+getOrigemX(), j+getOrigemY());
    }
  }
}
