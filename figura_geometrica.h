#ifndef FIGURA_H
#define FIGURA_H

class FiguraGeometrica{
private:
  int origemX, origemY;
  vector< vector<bool> > forma;
public:
  void setOrigem(int x, int y);
  int getOrigemX();
  int getOrigemY();
  void setForma(vector< vector<bool> > forma);
  vector< vector<bool> > getForma();
};

#endif // FIGURA_H