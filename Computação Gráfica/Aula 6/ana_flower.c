#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

float tx = 0.0;
float ty = 0.0;
float PI = 3.1415;
float theta = 0.0;
float alfa = 0.0;

void miolo(float r, float incX, float incY) {
	int i;
	float angulo = 0.0;
	glBegin(GL_POLYGON);
		for(i = 0; i <= 50; i++) {
			angulo = 2 * PI * i / 50.0;
			glVertex2f(r*cos(angulo+theta)+incX, r*sin(angulo+theta)+incY);
		}
	glEnd();
}

void petala(float r, float incX, float incY) {
	int i;
	float angulo = 0.0;
	glBegin(GL_POLYGON);
		for(i = 0; i <= 50; i++) {
			angulo = 2 * PI * i / 50.0;
			float x = r*cos(angulo)+incX;
			float y = r*sin(angulo)+incY;
			glVertex2f(x*cos(alfa) - y*sin(alfa), x*sin(alfa) + y*cos(alfa));
		}
	glEnd();
}

void caule() {
	glBegin(GL_POLYGON);
		glVertex2f(-0.05, -1);
		glVertex2f(0.05, -1);
		glVertex2f(0.05, 0.0);
		glVertex2f(-0.05, 0);
	glEnd();
}
 
void flor() {
	glColor3f(0.4,0.5,0.2);
	caule();
	
	glColor3f(1.0,1.0,1.0);
	petala(0.25,0.3675,0.2151);
	petala(0.25,0,0.4);
	petala(0.25,-0.3531,0.1899);
	petala(0.25,-0.358,-0.2004);
	petala(0.25,0.00952,-0.3894);
	petala(0.25,0.3554,-0.2);
	
	glColor3f(0.9,0.8,0.1);
	miolo(0.35,0,0);
}

void special_function(int tecla, int x, int y) {
	switch (tecla) {
		case GLUT_KEY_RIGHT:
			tx += 0.05;
			theta += 5;
			alfa += 0.05;
			break;
		case GLUT_KEY_LEFT:
			tx -= 0.05;
			theta -= 5;
			alfa -= 0.05;
			break;
		case GLUT_KEY_UP:
			ty += 0.05;
			break;
		case GLUT_KEY_DOWN:
			ty -= 0.05;
			break;
	}
	glutPostRedisplay();
}

void desenha() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
		
	flor();
	
	glFlush();
}

int main(int argc, char **argv) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(400,400);
	glutInit(&argc, argv);
	glutCreateWindow("Ana ");
	glutDisplayFunc(desenha);
	glutSpecialFunc(special_function);
	glutMainLoop();
	return 0;
}
