#include <vector>
#include "figura_geometrica.h"
using namespace std;

void FiguraGeometrica::setOrigem(int x, int y){
  origemX = x;
  origemY = y;
}

void FiguraGeometrica::setForma(vector< vector<bool> > forma){
  this->forma = forma;
}

vector< vector<bool> > FiguraGeometrica::getForma(){
  return forma;
}

int FiguraGeometrica::getOrigemX() {return origemX;}

int FiguraGeometrica::getOrigemY() {return origemY;}