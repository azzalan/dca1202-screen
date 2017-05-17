# dca1202-screen

Projeto avaliativo para a turma 2 do componente curricular DCA1202 do curso de Bacharelado em Ciência e Tecnologia da UFRN, período 2017.1.

<h1> DOCUMENTAÇÃO </h1>

<h4>Índice</h4>
<ol>
 <li>
  <a href="#screen">Screen</a>
  <ol>
   <li> <a href="#screena">Atributos privados</a></li>
   <li> <a href="#screenm">Métodos públicos</a> </li>
   <li> <a href="#screenx">Funções auxiliares</a> </li>
  </ol>
 </li>
 <li>
  <a href="#figura">Figura Geométrica</a>
  <ol>
   <li> <a href="#figuraa">Atributos privados</a></li>
   <li> <a href="#figuram">Métodos públicos</a> </li>
  </ol>
 </li>
 <li>
  <a href="#reta">Retângulo</a>
  <ol>
   <li> <a href="#retaa">Atributos privados</a></li>
   <li> <a href="#retam">Métodos públicos</a> </li>
  </ol>
 </li>
 <li>
  <a href="#retangulo">Retângulo</a>
  <ol>
   <li> <a href="#retanguloa">Atributos privados</a></li>
   <li> <a href="#retangulom">Métodos públicos</a> </li>
  </ol>
 </li>
</ol>

<h2 id="screen">CLASSE: Screen </h2>

<h4 id="screena">-Atributos privados</h4>
 
<b>int nlin, ncol</b><br/>
Armazenam o tamanho da tela de desenho no de linhas e de colunas.<br/>

<b>char brush</b>
Guarda o caractere usado para desenhar.<br/>

<b>vector< vector<char> > mat</b><br/>
Armazena a matriz da tela.<br/>
 
<h4 id="screenm">-Métodos públicos</h4>

<b>Screen(int nlin, int ncol)</b><br/>
<b>Screen()</b><br/>
Construtores da classe<br/>

<b>void iniciar(int nlin, int ncol)</b><br/>
Inicia tela atibuido-lhe altura e largura.<br/>

<b>  void setPixel(int x, int y);</b><br/>
Desenha um pixel da matriz usando o caratere guardado em 'brush'<br/>

<b>void clear()</b><br/>
Limpa a tela<br/>


<b>void setBrush(char brush)</b><br/>
Muda o caractere de desenho<br/>

<h4 id="screenx">-Funções auxiliares</h4>
<b>friend print(Screen &t)</b><br/>
Imprime a tela no console.<br/>

<b>friend ostream& operator<<(ostream &os, Screen &t)</b><br/>
Envia a tela para um stream de saida<br/>


<h2 id="figura">CLASSE: Figura Geométrica </h2>

<h4 id="figuraa">-Atributos privados</h4>

<b>int origemX, origemY</b><br/>
Guarda ponto origem da figura.<br/>

<b>vector< vector<bool> > forma</b><br/>
Matriz que guarda a forma da figura.<br/>
 
<h4 id="figuram">-Métodos públicos</h4>

<b>void setOrigem(int x, int y)</b><br/>
Seleciona a origem da figura.<br/>

<b>int getOrigemX()</b><br/>
Retorna o x da origem.<br/>

<b>int getOrigemY()</b><br/>
Retorna o y da origem.<br/>

<b>void setForma(vector< vector<bool> > forma)</b><br/>
Seleciona a forma da figura.<br/>

<b>vector< vector<bool> > getForma()</b><br/>
Retorna a forma da figura.<br/>

<h2 id="reta">CLASSE: Reta </h2>

<h4 id="retaa">-Atributos privados</h4>

<h4 id="retam">-Métodos públicos</h4>

<b>Reta(int p1x, int p1y, int p2x, int p2y)</b><br/>
Construtor da reta.<br/>

<b>void draw(Screen &t)</b><br/>
Aplica a figura a uma tela.<br/>

<h2 id="retangulo">CLASSE: Retângulo </h2>

<h4 id="retanguloa">-Atributos privados</h4>
 
<h4 id="retangulom">-Métodos públicos</h4>

<b>Retangulo(int x, int y, int largura, int altura)</b><br/>
Construtor do retângulo.<br/>

<b>void draw(Screen &t)</b><br/>
Aplica a figura a uma tela.<br/>
