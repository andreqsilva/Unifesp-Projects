#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float tx = 0.0;
float ty = 0.0;
float PI = 3.1415;
float theta = 0.0;

void quadrado(float incX, float incY) {
	float pmX = 0.4;	// ponto médio x
	float pmY = 0.2;	// ponto médio y
	float rotationXr = pmX-pmX*cos(theta) + pmY*sin(theta);
	float rotationYr = pmY-pmY*cos(theta) - pmX*sin(theta);
	
	glBegin(GL_POLYGON);
		glVertex2f(0.3*cos(theta)-0.3*sin(theta) + rotationXr, 0.3*sin(theta)+0.3*cos(theta) + rotationYr);
		glVertex2f(0.5*cos(theta)-0.3*sin(theta) + rotationXr, 0.5*sin(theta)+0.3*cos(theta) + rotationYr);
		glVertex2f(0.5*cos(theta)-0.1*sin(theta) + rotationXr, 0.5*sin(theta)+0.1*cos(theta) + rotationYr);
		glVertex2f(0.3*cos(theta)-0.1*sin(theta) + rotationXr, 0.3*sin(theta)+0.1*cos(theta) + rotationYr);
	glEnd();
}


void circulo(float r) {
	int i;
	float angulo = 0.0;
	glBegin(GL_LINE_LOOP);
		for(i = 0; i <= 5; i++) {
			angulo = 2 * PI * i / 10.0;
			glVertex2f(r*cos(angulo+theta), r*sin(angulo+theta));
		}
	glEnd();
}

void special_function(int tecla, int x, int y) {
	switch (tecla) {
		case GLUT_KEY_RIGHT:
			tx += 0.05;
			theta += 5;
			break;
		case GLUT_KEY_LEFT:
			tx -= 0.05;
			theta -= 5;
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
	
	glColor3f(1.0,0.0,0.0);
	quadrado(0.5,0.5);
	
	circulo(0.3);
	
	glFlush();
}

int main(int argc, char **argv) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(400,400);
	glutInit(&argc, argv);
	glutCreateWindow("Transformações Geométricas - Rotação");
	glutDisplayFunc(desenha);
	glutSpecialFunc(special_function);
	glutMainLoop();
	return 0;
}
