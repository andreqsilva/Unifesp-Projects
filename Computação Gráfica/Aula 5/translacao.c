#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float tx = 0.0;
float ty = 0.0;

void display_function() {
	glClear(GL_COLOR_BUFFER_BIT);

	// Para realizar a translação por (tx,ty)
	// x' = x + tx, y' = y + ty

	glBegin(GL_POLYGON);
		glVertex2f(-0.25+tx,0.25+ty);
		glVertex2f(0.25+tx,0.25+ty);
		glVertex2f(0.25+tx,-0.25+ty);
		glVertex2f(-0.25+tx,-0.25+ty);
	glEnd();
	glFlush();
}

void special_function(int tecla, int x, int y) {
	switch (tecla) {
		case GLUT_KEY_RIGHT:
			tx += 0.05;
			break;
		case GLUT_KEY_LEFT:
			tx -= 0.05;
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

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.78,0.0,0.0);
}

int main(int argc, char **argv) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(400,400);
	glutInit(&argc, argv);
	glutCreateWindow("Transformações Geométricas - Translação");
	init();
	glutDisplayFunc(display_function);
	glutSpecialFunc(special_function);
	glutMainLoop();
	return 0;
}
