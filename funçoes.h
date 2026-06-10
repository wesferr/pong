const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const char* WINDOW_TITLE = "Pong";

//Auxiliar de criação de quadrado:
void Quadrado(float x, float y, float tx, float ty, float R, float G, float B);

//Auxiliar de criação de circulo:
void Circulo(float x, float y,float radius, float r, float g, float b);

//construtor dos blocos moveis:
void Bloco();

//mapeadores de teclado:
void Teclado(unsigned char key, int x, int y); //teclas w e s
void TeclasEspeciais(int key, int x, int y); //setas

//mapeadores da bola:
void MoveBolinha(int n);//função de loop
void Calculo();//calcula o posicionamento
void Bolinha();//progeta a bola
void Placar();
void ValorPlacar();
bool Ready();
void DesenhaTexto(char *string, float x,float y);
