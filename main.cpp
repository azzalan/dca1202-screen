#include <stdio.h>
#include <vector>
// #include <cstdlib>
#include "screen.h"
#include "screen.cpp"
#include "figura_geometrica.h"
#include "figura_geometrica.cpp"
#include "reta.h"
#include "reta.cpp"
#include "retangulo.h"
#include "retangulo.cpp"
#include <iostream>     // std::cout, std::ostream, std::ios
#include <fstream>      // std::filebuf
#include <string>

using namespace std;

int main(){
  int largura, altura, para, x0, y0, x1, y1;
  int largurar, alturar, x0r, y0r;
  char x;
  bool lineEnd;
  Screen screen;
  string line, partial;
  // entrada
  ifstream myfile ("entrada.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      // dim largura altura
      if(line[0]=='d'){
        para = 1;
        partial = "";
        for (int i=4; i<line.length(); i++){
          lineEnd = (i==line.length()-1);
          if(line[i]==' '||lineEnd){
            if(lineEnd) {partial+=line[i];}
            switch(para){
              case 1:
                largura = atoi(partial.c_str());
                break;
              case 2:
                altura = atoi(partial.c_str());
                break;
            }
            partial = "";
            para++;
          } else partial+=line[i];
        }
        screen.iniciar(altura, largura);
      }
      // brush x
      if(line[0]=='b'){
        x = line[6];
        screen.setBrush(x);
      }
      // line x0 y0 x1 y1
      if(line[0]=='l'){
        para = 1;
        partial = "";
        for (int i=5; i<line.length(); i++){
          lineEnd = (i==line.length()-1);
          if(line[i]==' '||lineEnd){
            if(lineEnd) {partial+=line[i];}
            switch(para){
              case 1:
                x0 = atoi(partial.c_str());
                break;
              case 2:
                y0 = atoi(partial.c_str());
                break;
              case 3:
                x1 = atoi(partial.c_str());
                break;
              case 4:
                y1 = atoi(partial.c_str());
                break;
            }
            partial = "";
            para++;
          } else partial+=line[i];
        }
        Reta reta(x0, y0, x1, y1);
        reta.draw(screen);
      }
      // rectangle x0 y0 largura altura
      if(line[0]=='r'){
        para = 1;
        partial = "";
        for (int i=10; i<line.length(); i++){
          lineEnd = (i==line.length()-1);
          if(line[i]==' '||lineEnd){
            if(lineEnd) {partial+=line[i];}
            switch(para){
              case 1:
                x0r = atoi(partial.c_str());
                break;
              case 2:
                y0r = atoi(partial.c_str());
                break;
              case 3:
                largurar = atoi(partial.c_str());
                break;
              case 4:
                alturar = atoi(partial.c_str());
                break;
            }
            partial = "";
            para++;
          } else partial+=line[i];
        }
        Retangulo retangulo(x0r, y0r, largurar, alturar);
        retangulo.draw(screen);
      }
        // circle x0 y0 raio fillmode
        // case 'c':
    }
    myfile.close();
  }
  else cout << "Unable to open file"; 
  // saida
  filebuf fb;
  fb.open ("saida.txt", ios::out);
  ostream os(&fb);
  os << screen;
  fb.close();
  getchar();
  getchar();
  return 0;
}