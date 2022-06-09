#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float sx = 1.0;  // objeto sem sofrer alteração de escala
float sy = 1.0;

void display_function() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	// Para realizar a escala por (sx, sy)
	// x' = x*sx, y' = y*sy	
	
	glBegin(GL_POLYGON);
		glVertex2f(-0.25*sx,0.25*sy);
		glVertex2f(0.25*sx,0.25*sy);
		glVertex2f(0.25*sx,-0.25*sy);
		glVertex2f(-0.25*sx,-0.25*sy);
	glEnd();
	glFlush();
}

void special_function(int tecla, int x, int y) {
	switch (tecla) {
		case GLUT_KEY_UP:
			sx += 0.05;
			sy += 0.05;
			break;
		case GLUT_KEY_DOWN:
			sx -= 0.05;
			sy -= 0.05;
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
	glutCreateWindow("Transformações Geométricas - Escala");
	init();
	glutDisplayFunc(display_function);
	glutSpecialFunc(special_function);
	glutMainLoop();
	return 0;
}
