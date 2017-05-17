#ifndef RETA_H
#define RETA_H

class Reta: public FiguraGeometrica {
private:
  int fimX, fimY;
public:
  Reta(int p1x, int p1y, int p2x, int p2y);
  void draw(Screen &t);
};

#endif // RETA_H