#ifndef RETANGULO_H
#define RETANGULO_H

class Retangulo: public FiguraGeometrica {
public:
  Retangulo(int x, int y, int largura, int altura);
  void draw(Screen &t);
};

#endif // RETANGULO_H