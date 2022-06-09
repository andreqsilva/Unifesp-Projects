#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void drawTriangle() {
	glBegin(GL_TRIANGLES);
		glVertex2i(10,10);
		glVertex2i(20,50);
		glVertex2i(30,10);
	glEnd();
}

void init(){
     glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
}

void displayFunc() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	
	glLoadIdentity();
	gluOrtho2D(0.0f, 100.0f, 0.0f, 200.0f);
	glViewport(0.0, 0.0, 5.0, 10.0);
	glColor3f(0.0,1.0,0.0);
	drawTriangle();
	
	glutSwapBuffers();
}

int main(int argc, char *argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(400,400);
    glutCreateWindow("Viewing 2D");
    glutDisplayFunc(displayFunc);
    init();
    glutMainLoop();
    return 0;
}
