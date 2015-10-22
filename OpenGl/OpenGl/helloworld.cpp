#include<Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926535898


using namespace std; //para dizer que não precisa colocar namespace na frente do objeto criado por ela

unsigned char var;

void losangulo25D(float x, float y, float width, float height, float r, float g, float b) {
	glBegin(GL_POLYGON);
	glColor3f(r, g, b);
		glVertex2f(x, y);
		glVertex2f(x + width, y + (width /2));
		glVertex2f(x, y + (width));
		glVertex2f((x - width), y + (width / 2));
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(r * 0.8, g * 0.8, b * 0.8);
		glVertex2f(x, y);
		glVertex2f(x + width, y + (width / 2));
		glVertex2f(x + width, y + (width / 2) - height);
		glVertex2f(x, y - height);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(r * 0.8, g * 0.8, b * 0.8);
	glVertex2f(x, y);
	glVertex2f((x - width), y + (width / 2));
	glVertex2f((x - width), y + (width / 2) - height);
	glVertex2f(x, y - height);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0);
	glVertex2f(x, y);
	glVertex2f(x + width, y + (width / 2));
	glVertex2f(x, y + (width));
	glVertex2f((x - width), y + (width / 2));
	glEnd();
}
	void display()
	{
		/*  clear all pixels  */
		glClear(GL_COLOR_BUFFER_BIT);

		/*  draw white polygon (rectangle) with corners at
		*  (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
		*/
		glColor3f(1.0, 1.0, 1.0);
		if (var == 'a') {
			glBegin(GL_POLYGON); // ou glBegin(GL_POINTS);
			glVertex2f(0.0, 0.0);
			glVertex2f(0.0, 0.30);
			glVertex2f(0.40, 0.30);
			glVertex2f(0.60, 0.15);
			glVertex2f(0.40, 0.0);
			glEnd();
			glutPostRedisplay();
		} else if (var == 'b') {
			GLfloat circle_points = 50.5f;
			GLfloat angle, raioX = 0.55f, raioY = 0.55f;
			glBegin(GL_LINE_LOOP);
			for (int i = 0; i < circle_points; i++) {
				angle = 2 * PI*i / circle_points;
				glVertex2f(cos(angle)*raioX,
					sin(angle)*raioY);
			}
			glEnd();
			glutPostRedisplay();
		}
		else if (var == 'c') {
			GLfloat circle_points = 90.0f;
			GLfloat angle, raioX = 0.50f, raioY = 0.50f;
			glBegin(GL_LINE_LOOP);
			for (int i = 0; i < circle_points; i++) {
				angle = 2 * PI*i / circle_points;
				glVertex2f(cos(angle)*raioX,
					sin(angle)*raioY);
			}
			glEnd();
			glutPostRedisplay();
		}
		else if (var == 'd') {
			GLfloat circle_points = 90.5f;
			GLfloat angle, raioX = 0.55f, raioY = 0.11f;
			glBegin(GL_LINE_LOOP);
			for (int i = 0; i < circle_points; i++) {
				angle = 2 * PI*i / circle_points;
				glVertex2f(cos(angle)*raioX,
					sin(angle)*raioY);
			}
			glEnd();
			glutPostRedisplay();
		}
		else if (var == 's') {
			GLfloat circle_points = 90.5f;
			GLfloat angle, raioX = 1.00f, raioY = 0.55f;
			glBegin(GL_LINE_LOOP);
			for (int i = 45; i < circle_points; i++) {
				angle = 2 * PI*i / circle_points;
				glVertex2f(cos(angle)*raioX,
					sin(angle)*raioY);
			}
			glEnd();
			glutPostRedisplay();
		}
		else if (var == 'f') {
			//define fatia de pizza
			GLfloat circle_points = 5.0f;
			GLfloat angle, raioX = 0.55f, raioY = 0.55f;
			glBegin(GL_LINE_LOOP);
			for (int i = 0; i < circle_points / 2; i++) {
				angle = 2 * PI*i / circle_points;
				glVertex2f(cos(angle)*raioX,
					sin(angle)*raioY);
			}
			glEnd();
			glutPostRedisplay();
		}

		else if (var == 'h') {
			GLfloat circle_points = 90.5f;
			GLfloat angle, raioX = 1.00f, raioY = 0.55f;
			glBegin(GL_POLYGON);
			for (int i = 45; i < circle_points; i++) {
				angle = 2 * PI*i / circle_points;
				glVertex2f(cos(angle)*raioX,
					sin(angle)*raioY);
			}
			glEnd();
			glutPostRedisplay();

		}
		else if (var == '2') {
			glBegin(GL_POLYGON);
			glColor3f(1.0, 1.0, 1.0);
			glVertex2f(1.0, 0.0);
			glVertex2f(0.0, 1.0);
			glVertex2f(-1.0, 0.0);
			glVertex2f(0.0, -1.0);
			glEnd();
			glutPostRedisplay();
		}
		else if (var == '3') {
			glBegin(GL_POLYGON);
			glColor3f(0.44, 0.44, 0.44);
			glVertex2f(0.5, 0.0);
			glVertex2f(0.0, 0.5);
			glVertex2f(-0.5, 0.0);
			glVertex2f(0.0, -0.5);
			glEnd();
			glFlush();

			glBegin(GL_POLYGON);
			glColor3f(0.55, 0.55, 0.55);
			glVertex2f(-0.5, 0.0);
			glVertex2f(-0.5, -0.12);
			glVertex2f(0.0, -0.62);
		    glVertex2f(0.0, -0.50);
			glEnd();
			glFlush();

			glBegin(GL_POLYGON);
			glColor3f(0.22, 0.22, 0.22);
			glVertex2f(0.5, 0.0);
			glVertex2f(0.5, -0.12);
			glVertex2f(0.0, -0.62);
			glVertex2f(0.0, -0.50);
			//glVertex2f()
			glEnd();
			glFlush();
		}
		else if (var == '4') {
			losangulo25D(0.0, 0.5, 0.4, 0.1, 0.8, 0.8, 0.8);
			losangulo25D(-0.4, 0.3, 0.4, 0.1, 0.8, 0.8, 0.8);
			losangulo25D(-0.8, 0.1, 0.4, 0.1, 0.8, 0.8, 0.8);
			losangulo25D(-1.2, -0.1, 0.4, 0.1, 0.8, 0.8, 0.8);
			losangulo25D(0.4, 0.3, 0.4, 0.1, 0.8, 0.8, 0.8);
			losangulo25D(0.0, 0.0, 0.4, 0.1, 0.4, 0.4, 0.4);
			losangulo25D(-0.4, -0.2, 0.4, 0.1, 0.4, 0.4, 0.4);
			losangulo25D(-0.8, -0.3, 0.4, 0.1, 0.8, 0.8, 0.8);
			losangulo25D(0.8, 0.1, 0.4, 0.1, 0.8, 0.8, 0.8);
			losangulo25D(0.4, -0.1, 0.4, 0.1, 0.6, 0.7, 8);
			losangulo25D(0.0, -0.4, 0.4, 0.1, 0.4, 0.4, 0.4);
			losangulo25D(-0.4, -0.5, 0.4, 0.1, 0.8, 0.8, 0.8);
			losangulo25D(1.2, -0.1, 0.4, 0.1, 0.8, 0.8, 0.8);
			losangulo25D(0.8, -0.3, 0.4, 0.1, 0.8, 0.8, 0.8);
			losangulo25D(0.4, -0.5, 0.4, 0.1, 0.8, 0.8, 0.8);
			losangulo25D(0.0, -0.7, 0.4, 0.1, 0.8, 0.8, 0.8);
			glFlush();

		}
		/*  don't wait!
		*  start processing buffered OpenGL routines
		*/
		glFlush();
	}

	void desenhaSlideMap() {

	}

	void keyboard(unsigned char key, int x, int y) {
		if (key == 'q') {
			exit(0);
		}
		var = key;
	}

	void init(void){
		/*  select clearing (background) color       */
		glClearColor(0.00, 0.0, 30.0, 0.0);

		/*  initialize viewing values  */
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.5, 0.5, 0.5, 00.0, 00.0, 20.0);
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
