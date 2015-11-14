#include<Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include "IsometricView.h"
#include "TileMap.h"

using namespace std; //para dizer que não precisa colocar namespace na frente do objeto criado por ela

unsigned char var;

int controlador = 0;
/*
CONST INT N = 1;
CONST INT NE = 2;
CONST INT E = 3;
CONST INT SE = 4;
CONST INT S = 5;
CONST INT SW = 6;
CONST INT W = 7;
CONST INT NW = 8;
//constantes para rosa dos ventos
*/

const int TX = 16;
const int TY = 16;
//numero de tiles

int windowW = 1024;
int windowH = 700;

int x = 0;
int y = 0;
int larguraTile = 32;
int alturaTile = 16;

IsometricView iv;

int  cont = 1;
void desenha(int x, int y) {
	if (controlador == 0) {
		glColor3f(0, 0, 0);
	}
	else if (controlador == -1) {
		glColor3f(0, 0, 125);
	}
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x + larguraTile, y + (larguraTile / 2));
	glVertex2f(x, y + (larguraTile));
	glVertex2f((x - larguraTile), y + (larguraTile / 2));
	glEnd();

	glColor3f(255, 255, 255);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x, y);
	glVertex2f(x + larguraTile, y + (larguraTile / 2));
	glVertex2f(x, y + (larguraTile));
	glVertex2f((x - larguraTile), y + (larguraTile / 2));
	glEnd();

}


void calcTilePosition(int col, int lin) {
	x = (col * larguraTile) + (lin * (larguraTile / 2));
	y = lin * (alturaTile / 2);
}

void calcTileDiamont(int col, int lin) {
	x = (col - lin) * larguraTile;
	y = (col + lin) * alturaTile;
}
void desenhaSlideMap() {


	for (int i = 0; i < TX; i++) {
		for (int j = 0; j < TY; j++) {
			calcTileDiamont(i, j);
			desenha(x + 500, y + 150);
		}
		if (controlador == 0) {
			controlador = -1;
		}
		else if (controlador == -1) {
			controlador = 0;
		}
	}
	for (int i = TX; i > TX; i--) {
		for (int j = TX; j > TY; j--) {
			calcTileDiamont(i, j);
			desenha(x + 300, y + 300);

		}
	}
}

void display() {

	glClear(GL_COLOR_BUFFER_BIT);
	desenhaSlideMap();

	glutPostRedisplay();
	glFlush();
}


void keyboard(unsigned char key, int x, int y) {
	//TODO
}

void init(void) {
	/*  select clearing (background) color       */
	glClearColor(0.1, 0.1, 0.2, 0.0);

	glViewport(0, 0, windowW, windowH);

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Set the clipping volume
	gluOrtho2D(0.0, windowW, 0.0, windowH);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*
*  Declare initial window size, position, and display mode
*  (single buffer and RGBA).  Open window with "hello"
*  in its title bar.  Call initialization routines.
*  Register callback function to display graphics.
*  Enter main loop and process events.
*/
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(windowW, windowH);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Trabalho GrauB");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;   /* ISO C requires main to return int. */
}
