#ifndef RETA_H
#define RETA_H

class Reta: public FiguraGeometrica {
public:
  Reta(int p1x, int p1y, int p2x, int p2y);
  void draw(Screen &t);
};

#endif // RETA_H