#include <windows.h>
#include <gl/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

bool ready = false;
float py1;
float py2;
bool eixox, eixoy;
float bx = 0.0, by = 0.0, passox = 0.001;
const float DEG2RAD = 3.14159/180;
int placar1 = 0;
int placar2 = 0;

void Circulo(GLfloat x, GLfloat y, GLfloat radius, GLfloat r, GLfloat g, GLfloat b) {
    int i;
    int triangleAmount = 30;
    GLfloat twicePi = 2.0f * M_PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(r,g,b);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

void Quadrado(GLfloat x, GLfloat y, GLfloat tx, GLfloat ty, GLfloat R, GLfloat G, GLfloat B) {
    glBegin(GL_QUADS);
    glColor3f(R, G, B);
    glVertex2f(x,y+ty);
    glVertex2f(x,y);
    glVertex2f(x+tx,y);
    glVertex2f(x+tx,y+ty);
    glEnd();
}

void DesenhaTexto(char *string, float x,float y){
  	glPushMatrix();
        glRasterPos2f(x,y);
        while(*string)
             glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*string++);
	glPopMatrix();
}

void Bloco() {
    Quadrado(0.8,py1,0.05,0.6,1.0,1.0,1.0);
    Quadrado(-0.85,py2,0.05,0.6,1.0,1.0,1.0);
}

void Bolinha() {
    Circulo(bx,by,0.03, 1.0,1.0,1.0);
}

void Placar(){
    char splacar1[10];
    char splacar2[10];
    sprintf(splacar1, "%i", placar1);
    sprintf(splacar2, "%i", placar2);
    DesenhaTexto(splacar1 , 0.2, 0.6);
    DesenhaTexto(splacar2 , -0.2, 0.6);
    if((placar1 == 10) || (placar2 == 10)){
        bx = 0.0;
        by = 0.0;
        placar1 = 0;
        placar2 = 0;
        eixox = true;
        eixoy = true;
        py1 = 0.0;
        py2 = 0.0;
        ready = false;
        }
}

void Teclado(unsigned char key, int x, int y) {
    switch (key) {
    case 'W':
    case 'w':
        if(py2 < 0.4)py2 += 0.06;
        break;
    case 'S':
    case 's':
        if(py2 > -1.0)py2 -= 0.06;
        break;
    }
    glutPostRedisplay();
}

void TeclasEspeciais(int key, int x, int y) {
    if(key == GLUT_KEY_UP) {
        if(py1 < 0.4)py1 += 0.05;
    }
    if(key == GLUT_KEY_DOWN) {
        if(py1 > -1.0)py1 -= 0.05;
    }
    if(key == GLUT_KEY_UP){
        ready = true;
    }
    glutPostRedisplay();
}

int Calculo() {

    if(eixox == true) {
        bx += passox;
        if(bx >= 1.0) eixox = false;
    }
    if(eixox == false) {
        bx -= passox;
        if(bx <= -1.0) eixox = true;
    }
    if(eixoy == true) {
        by += passox;
        if(by >= 1.0) eixoy = false;
    }
    if(eixoy == false) {
        by -= passox;
        if(by <= -1.0) eixoy = true;
    }
    if(((by > py1) && (by < py1+0.6)) && ((bx > 0.8) && (bx < 0.8+0.5))) {
        if (eixox = false) eixox = true;
        if (eixox = true) eixox = false;
    }
    if(((by > py2) && (by < py2+0.6)) && ((bx > -0.85))&& (bx < -0.8)) {
        if (eixox = false) eixox = false;
        if (eixox = true) eixox = true;
    }

}

void MoveBolinha(int n) {
    Calculo();
    glutTimerFunc(1, MoveBolinha, 1);
    glutPostRedisplay();
}

void ValorPlacar(){
    if(bx > 0.9999906) placar1++;
    if(bx < -0.999999) placar2++;
}

bool Ready(){
    return (ready);
}
