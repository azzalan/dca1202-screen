#ifndef CIRCULO_H
#define CIRCULO_H

class Circulo: public FiguraGeometrica {
private:
  int centroX, centroY, raio;
  bool fill;
public:
  Circulo(int x0, int y0, int r);
  void draw(Screen &t);
};

#endif // CIRCULO_H