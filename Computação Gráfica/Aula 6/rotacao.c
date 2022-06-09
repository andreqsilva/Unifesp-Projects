#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float tx = 0.0;
float ty = 0.0;
float PI = 3.1415;
float theta = 0.0;

void quadrado(float incX, float incY) {
	glBegin(GL_POLYGON);
		glVertex2f(-0.25+incX,0.25+incY);
		glVertex2f(0.25+incX,0.25+incY);
		glVertex2f(0.25+incX,-0.25+incY);
		glVertex2f(-0.25+incX,-0.25+incY);
	glEnd();
}

void circulo(float incX, float incY) {
	int i;
	float angulo = 0.0;
	glBegin(GL_LINE_LOOP);
		for(i = 0; i <= 10; i++) {
			angulo = 2 * PI * i / 10.0;
			glVertex2f(0.250*cos(angulo)+incX, 0.250*sin(angulo)+incY);
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
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1.0,1.0,1.0);
	glPushMatrix();
	glRotatef(theta,0.0,0.0,1.0);
	circulo(0.5,0.5);
	glPopMatrix();

	
	/*
	glPushMatrix();
	glColor3f(1.0,0.0,0.0);
	
	glTranslatef(-0.5,-0.5,0.0); // Translade de volta
	glRotatef(45.0,0.0,0.0,1.0); // Rotacione em torno da origem
	glTranslatef(0.5,0.5,0.0); // Translade ate a origem
	quadrado(0.0,0.0);
	glPopMatrix();
	*/
	
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
