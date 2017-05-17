#include <vector>

#ifndef SCREEN_H
#define SCREEN_H

class Screen{
private:
  // armazenam o tamanho da tela de desenho
  // no de linhas e de colunas
  int nlin, ncol;

  // guarda o caractere usado para desenhar
  char brush;

  // armazena a matriz da tela
  vector< vector<char> > mat;
public:
  // construtor da classe
  Screen(int nlin, int ncol);
  Screen();
  void iniciar(int nlin, int ncol);
  // desenha um pixel da matriz usando o caratere
  // guardado em 'brush'
  void setPixel(int x, int y);
  int getNlin() {return nlin;}
  int getNcol() {return ncol;}
  // limpa a tela
  void clear();

  // muda o caractere de desenho
  void setBrush(char brush);

  // envia a tela para um stream de saida
  friend print(Screen &t);
  friend ostream& operator<<(ostream &os, Screen &t);
};

#endif // SCREEN_H