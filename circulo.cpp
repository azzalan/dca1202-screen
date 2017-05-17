#include <vector>
#include <iostream>
#include "circulo.h"
using namespace std;

Circulo::Circulo(int x0, int y0, int r){
  int ofX, ofY, origemX, origemY;
  ofX = x0-r;
  ofY = y0-r;
  setOrigem(ofX, ofY);
  origemX = r+1;
  origemY = r+1;
  vector< vector<bool> > linhas(2*r+1);
  vector<bool> linha(2*r+1);
  for(int i=0; i<(2*r+1); i++){
    linhas[i] = linha;
  }
  for(int y=-r; y<=r; y++)
      for(int x=-r; x<=r; x++)
          if(x*x+y*y <= r*r)
              linhas[origemY+y][origemX+x]=true;
  setForma(linhas);
}

void Circulo::draw(Screen &t){
  vector< vector<bool> > formax = getForma();
  for(int i=0; i<formax.size(); i++){
    for(int j=0; j<formax[i].size(); j++){
      if(formax[i][j]) t.setPixel(i+getOrigemX(), j+getOrigemY());
    }
  }
}