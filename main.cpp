#include <windows.h>
#include <gl/glut.h>
#include "funçoes.h"
#include <time.h>

//redimencionamento da tela
void Reshape(int w, int h) {
    if(h==0) h=1;
    float aspecRatio = (float) w/h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45, aspecRatio, .1, 1000);
}

//atualização da tela
void Display() {
    bool ready = false;
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    ready = Ready();
    if(ready == false){
        DesenhaTexto("BEM VINDO AO PONG", -0.3,0.6);
        DesenhaTexto("Para jogar basta usar o 'W' e o 'S' para mover o bloco da esquerda ", -0.85,0.3);
        DesenhaTexto("e as seta 'CIMA' e 'BAIXO' para mover o bloco da direita", -0.75,0.2);
        DesenhaTexto("O jogo vai ate 10 pontos", -0.33,0.1);
        DesenhaTexto("Para começar aperte a seta 'CIMA'", -0.45,0.0);
    }
    if(ready == true){
    Bloco();
    Placar();
    ValorPlacar();
    Bolinha();
    }
    glutSwapBuffers();
    glFlush();
}
int main(int argc, char *argv) {
    //inicia opengl
    glutInit(&argc, &argv);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

    //cria a janela
    glutCreateWindow(WINDOW_TITLE);

    //chama as funçoes
    glutReshapeFunc(Reshape);
    glutDisplayFunc(Display);
    glutKeyboardFunc(Teclado);
    MoveBolinha(100);
    glutSpecialFunc(TeclasEspeciais);
    glutMainLoop();
    return 0;
}
