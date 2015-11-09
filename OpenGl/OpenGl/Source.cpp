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

CONST INT N = 1;
CONST INT NE = 2;
CONST INT E = 3;
CONST INT SE = 4;
CONST INT S = 5;
CONST INT SW = 6;
CONST INT W = 7;
CONST INT NW = 8;

const int TW = 10;
const int TH = 10;

int x = 0;
int y = 0;
int larguraTile = 64;
int alturaTile = 32;

IsometricView iv;


void desenha(int x, int y) {
	glBegin(GL_POLYGON);
	glColor3f(255.0, 255.0, 255.0);
	glVertex2f(x, y);
	glVertex2f(x + larguraTile, y + (larguraTile / 2));
	glVertex2f(x, y + (larguraTile));
	glVertex2f((x - larguraTile), y + (larguraTile / 2));
	glEnd();

}

void desenhalinha(int x, int y) {

	glBegin(GL_LINE);
	glColor3f(0, 255.0, 0);
	glVertex2f(x, y);
	glVertex2f(x + larguraTile, y + (larguraTile / 2));
	glVertex2f(x, y + (larguraTile));
	glVertex2f((x - larguraTile), y + (larguraTile / 2));
	glEnd();
}
void calcTilePosition(int col, int lin) {
	x = (col * larguraTile) + (lin * (larguraTile/2));
	y = lin * (alturaTile);
}

void desenhaSlideMap(int &x, int &y) {
	for (int i = 0; i < TW; i++) {
		for (int j = 0; j < TH; j++) {
			calcTilePosition(i, j);
			desenha(x,y);
			desenhalinha(x, y);
		}
	}
}

void display(){
	
	glClear(GL_COLOR_BUFFER_BIT);
	desenhaSlideMap(x, y);
	
	
/*	if (controlador == 0) {
		controlador = 1;
		glBegin(GL_POLYGON); // ou glBegin(GL_POINTS);
		printf("Entrou no display");
		glVertex2f(0.0, 0.0);
		glVertex2f(0.0, 0.30);
		glVertex2f(0.40, 0.30);
		glVertex2f(0.60, 0.15);
		glVertex2f(0.40, 0.0);
		glEnd();
		glutPostRedisplay();
		glClear(GL_COLOR_BUFFER_BIT);
	}
	*/glFlush();
}


void keyboard(unsigned char key, int x, int y) {
	//TODO
}

void init(void) {
	/*  select clearing (background) color       */
	glClearColor(0.00, 0.0, 3.0, 0.0);

	glViewport(0, 0, 800, 600);

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Set the clipping volume
	gluOrtho2D(0.0f, 800, 0.0, 600);

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
	glutInitWindowSize(800, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Trabalho GrauB");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;   /* ISO C requires main to return int. */
}
