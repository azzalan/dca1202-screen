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
    linhas[l][j] = true;
    count += passoY;
    if(count>0) tamCount = count;
    else tamCount = -count;
    if(passoY>=0) {
      for(int z=1; z<=tamCount; z++){
        l++;
        linhas[l][j] = true;
        count--;
      }
    } else {
      for(int z=1; z<=tamCount; z++){
        l--;
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

// Reta::Reta(int p1x, int p1y, int p2x, int p2y){
//   if (p1x<p2x) {
//     setOrigem(p1x, p1y);
//     fimX = p2x;
//     fimY = p2y;
//   } else if (p1x==p2x) {
//     if(p1y<p2y) {
//       setOrigem(p1x, p1y);
//       fimX = p2x;
//       fimY = p2y;
//     } else {
//       setOrigem(p2x, p2y);
//       fimX = p1x;
//       fimY = p1y;
//     }
//   } else {
//     setOrigem(p2x, p2y);
//     fimX = p1x;
//     fimY = p1y;
//   }
// }

// void Reta::draw(Screen &t){
//   int linha, col;
//   float count, tamCount, passoY;
//   int oX = getOrigemX();
//   int oY = getOrigemY();
//   int distX = fimX - oX;
//   int distY = fimY - oY;
//   if(distX!=0) passoY = distY/distX;
//   if(distX==0) {
//     col = oX;
//     for(linha=oY;linha<fimY;linha++) {
//       cout << col << " "<< linha << endl;
//       t.setPixel(col, linha);
//     }
//   } else if(distY==0) {
//     cout << col << " "<< linha << endl;
//     linha = oY;
//     for(col=oX;col<fimY+1;col++) {
//       t.setPixel(col, linha);
//     }
//   } else if(distY<0) {
//     linha = oX;
//     col = oY;
//     count = 0;
//     for(col=oY; col<fimY+1; col++) {
//       count += passoY;
//       tamCount = count;
//       for(int i=0; i<tamCount; i++) {
//         linha--;
//         t.setPixel(col, linha);
//         count--;
//       }
//     }
//   }
// }
