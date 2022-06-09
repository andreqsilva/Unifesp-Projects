#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float tx = 0.0;
float ty = 0.0;
float PI = 3.1415;
float theta = 0.0;

void circulo(float r, float incX, float incY) {
	int i;
	float angulo = 0.0;
	glBegin(GL_POLYGON);
		for(i = 0; i <= 50; i++) {
			angulo = 2 * PI * i / 50.0;
			glVertex2f(r*cos(angulo)+incX, r*sin(angulo)+incY);
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
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
		
	glColor3f(0.4,0.5,0.2);
	caule();
	
	glColor3f(1.0,1.0,1.0);
	glPushMatrix();
	glRotatef(theta,0.0,0.0,1.0);
	circulo(0.25,0.3675,0.2151);
	circulo(0.25,0,0.4);
	circulo(0.25,-0.3531,0.1899);
	circulo(0.25,-0.358,-0.2004);
	circulo(0.25,0.00952,-0.3894);
	circulo(0.25,0.3554,-0.2);
	glPopMatrix();
	
	glColor3f(0.9,0.8,0.1);
	circulo(0.35,0,0);
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
	glClearColor(0.2,0.8,0.9,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
		
	flor();
	
	glFlush();
}

int main(int argc, char **argv) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(400,400);
	glutInit(&argc, argv);
	glutCreateWindow("Flower");
	glutDisplayFunc(desenha);
	glutSpecialFunc(special_function);
	glutMainLoop();
	return 0;
}
