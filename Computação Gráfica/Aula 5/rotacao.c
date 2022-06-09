#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float theta = 0.0;

void display_function() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	// Para realizar a rotação
	// x' = x*cos(theta) - y*sen(theta)
	// y' = x*sen(theta) + y*cos(theta)
	
	glBegin(GL_POLYGON);
		glVertex2f(-0.25*cos(theta)-0.25*sin(theta), -0.25*sin(theta)+0.25*cos(theta));
		glVertex2f(0.25*cos(theta)-0.25*sin(theta), 0.25*sin(theta)+0.25*cos(theta));
		glVertex2f(0.25*cos(theta)+0.25*sin(theta), 0.25*sin(theta)-0.25*cos(theta));
		glVertex2f(-0.25*cos(theta)+0.25*sin(theta), -0.25*sin(theta)-0.25*cos(theta));
	glEnd();
	glFlush();
}

void special_function(int tecla, int x, int y) {
	switch (tecla) {
		case GLUT_KEY_UP:
			theta += 0.05;
			break;
		case GLUT_KEY_DOWN:
			theta -= 0.05;
			break; 
	}
	glutPostRedisplay();
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0,1.0,1.0);
}

int main(int argc, char **argv) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(400,400);
	glutInit(&argc, argv);
	glutCreateWindow("Transformações Geométricas - Rotação");
	init();
	glutDisplayFunc(display_function);
	glutSpecialFunc(special_function);
	glutMainLoop();
	return 0;
}
