#include<Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include "IsometricView.h"
#include "TileMap.h"

using namespace std; //para dizer que não precisa colocar namespace na frente do objeto criado por ela

unsigned char var;

CONST INT N = 1;
CONST INT NE = 2;
CONST INT E = 3;
CONST INT SE = 4;
CONST INT S = 5;
CONST INT SW = 6;
CONST INT W = 7;
CONST INT NW = 8;

const int TX = 10;
const int TY = 10;

IsometricView iv = new IsometricView();

void desenha( int largura, int altura, int &x, int &y) {
	glBegin(GL_POLYGON);
	glColor3f(255.0, 255.0, 255.0);
	glVertex2f(x, y);
	glVertex2f(x + largura, y + (largura / 2));
	glVertex2f(x, y + (largura));
	glVertex2f((x - largura), y + (largura / 2));
	glEnd();
}

void display()
{
	for (int i = 0; i < TX; i++) {
		for (int j = 0; j < TY; j++) {
			iv.calcTilePosition(i, j);
			desenha(i, j, x, y);
			
		}
	}
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}


void keyboard(unsigned char key, int x, int y) {
	if (key == 'q') {
		exit(0);
	}
	var = key;
}

void init(void) {
	/*  select clearing (background) color       */
	glClearColor(0.00, 0.0, 30.0, 0.0);

	/*  initialize viewing values  */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0f, 600.0f, 0.0f, 400.0f);
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
	glutCreateWindow("hello");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;   /* ISO C requires main to return int. */
}
