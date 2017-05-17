#include <vector>
#include <iostream>
#include "reta.h"
using namespace std;

Reta::Reta(int p1x, int p1y, int p2x, int p2y){
  int oX, oY, tamX, tamY, distX, distY, inicioY, l;
  float passoY, count, tamCount;
  if(p1x<=p2x) oX = p1x;
  else oX = p2x;
  if(p1y<=p2y) {
    oY = p1y;
    inicioY = 0;
  } else {
    oY = p2y;
    inicioY = p1y-p2y;
  }
  setOrigem(oX, oY);
  distX = p2x - p1x;
  distY = p2y - p1y;
  if (distX>=0) tamX = 1+distX;
  else tamX = 1-distX;
  if (distY>=0) tamY = 1+distY;
  else tamY = 1-distY;
  vector< vector<bool> > linhas(tamY);
  vector<bool> linha(tamX);
  for(int i=0; i<tamY; i++){
    linhas[i] = linha;
  }
  passoY = distY/float(tamX);
  l = inicioY;
  count = 0;
  for(int j=0; j<tamX; j++){
    cout << "j: " << j << endl;
    cout << "l: " << l << endl;
    linhas[l][j] = true;
    count += passoY;
    if(count>0) tamCount = count;
    else tamCount = -count;
    if(passoY>=0) {
      for(int z=1; z<=tamCount; z++){
        l++;
        cout << "l: " << l << endl;
        linhas[l][j] = true;
        count--;
      }
    } else {
      for(int z=1; z<=tamCount; z++){
        l--;
        cout << "l: " << l << endl;
        linhas[l][j] = true;
        count++;
      }
    }
  }
  setForma(linhas);
}

void Reta::draw(Screen &t){
  vector< vector<bool> > formax = getForma();
  for(int i=0; i<formax.size(); i++){
    for(int j=0; j<formax[i].size(); j++){
      if(formax[i][j]) t.setPixel(i+getOrigemX(), j+getOrigemY());
    }
  }
}
