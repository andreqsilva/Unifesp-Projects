#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float theta = 1.5708;	//1.5708 = 90º 
float incX = -0.6;	//-0.6

void triangulo() {
	float pmX = 0.8;	
	float pmY = 0.4;	
	float rotationXr = pmX-pmX*cos(theta) + pmY*sin(theta);
	float rotationYr = pmY-pmY*cos(theta) - pmX*sin(theta);
	
	glBegin(GL_POLYGON);
		glVertex2f(0.5*cos(theta)-0.2*sin(theta)+rotationXr+incX, 0.5*sin(theta)+0.2*cos(theta)+rotationYr);
		glVertex2f(1.1*cos(theta)-0.2*sin(theta)+rotationXr+incX, 1.1*sin(theta)+0.2*cos(theta)+rotationYr);
		glVertex2f(0.8*cos(theta)-0.6*sin(theta)+rotationXr+incX, 0.8*sin(theta)+0.6*cos(theta)+rotationYr);
	glEnd();
}

void triangulo_2() {
	glBegin(GL_POLYGON);
		glVertex2f(0.4,0.1);
		glVertex2f(0.4,0.7);
		glVertex2f(0.0,0.4);
	glEnd();
}

void desenha() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(0.0,1.0,0.0);
	triangulo_2();
	glColor3f(0.8,0.0,0.0);
	triangulo();
	
	glFlush();
}

void special_function(int tecla, int x, int y) {
	switch (tecla) {
		case GLUT_KEY_RIGHT:
			incX += 0.05;
			break;
		case GLUT_KEY_LEFT:
			incX -= 0.05;
			break;
		case GLUT_KEY_UP:
			theta += 0.005;
			break;
		case GLUT_KEY_DOWN:
			theta -= 0.005;
			break;
	}
	printf("theta=%.2f \n", theta);
	printf("incX=%.2f \n", incX);
	glutPostRedisplay();
}

int main(int argc, char **argv) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(400,400);
	glutInit(&argc, argv);
	glutCreateWindow("Triangulo");
	glutDisplayFunc(desenha);
	glutSpecialFunc(special_function);
	glutMainLoop();
	return 0;
}
