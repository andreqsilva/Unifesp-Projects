#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float tx = 0.0;
float PI = 3.1415;
float theta = 0.0;

void estrada() {
	glBegin(GL_POLYGON);
		glVertex2f(-1.0, -0.6);
		glVertex2f(-1.0, -1.0);
		glVertex2f(1.0, -1.0);
		glVertex2f(1.0, -0.6);
	glEnd();
}

void line(float px_0, float py_0, float px_1, float py_1) {
	glLineWidth(2.4f);
	glBegin(GL_LINES);
		glVertex2f(px_0,py_0);
		glVertex2f(px_1,py_1);
	glEnd();
}

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

void semi_circulo(float r, float incX, float incY) {
	int i;
	float angulo = 0.0;
	glBegin(GL_POLYGON);
		for(i = 0; i <= 50; i++) {
			angulo = 2 * PI * i / 100.0;
			glVertex2f(r*cos(angulo)+incX, r*sin(angulo)+incY);
		}
	glEnd();
}

void car() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	// sol
	glColor3f(0.9,0.6,0.2);
	semi_circulo(1.0,0.0,-0.6);
	
	// capô
	glPushMatrix();
	glTranslatef(tx,0.0,0.0);
	glColor3f(1.0,0.0,0.0);
	circulo(0.1437,-0.6547,-0.5165);
	circulo(0.1437,-0.1138,-0.5164);
	circulo(0.2444,-0.3822,-0.4044);
	glColor3f(1.0,1.0,0.0);
	circulo(0.02,-0.0277,-0.4610);
	glColor3f(1.0,1.0,1.0);
	semi_circulo(0.1980,-0.3825,-0.3917);		
	glPopMatrix();
	
	// estrada
	glColor3f(0.0,0.0,0.0);
	estrada();
	glColor3f(1.0,1.0,0.0);
	line(-0.8,-0.8,-0.6,-0.8);
	line(-0.4,-0.8,-0.2,-0.8);
	line(0.0,-0.8,0.2,-0.8);
	line(0.4,-0.8,0.6,-0.8);
	line(0.8,-0.8,1.0,-0.8);
	
	// rodas
	glPushMatrix();
	glColor3f(0.3,0.3,0.3);
	glTranslatef(-0.6269+tx,-0.5995,0.0);
	glRotatef(theta,0.0,0.0,1.0);
	glTranslatef(0.6269,0.5995,0.0);
	circulo(0.12,-0.6269,-0.5995);
	glColor3f(0.5,0.8,0.0);
	circulo(0.0623,-0.6269,-0.5995);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.3,0.3,0.3);
	glTranslatef(-0.1418+tx,-0.6004,0.0);
	glRotatef(theta,0.0,0.0,1.0);
	glTranslatef(0.1418,0.6004,0.0);	
	circulo(0.12,-0.1418,-0.6004);
	glColor3f(0.5,0.8,0.0);
	circulo(0.0623,-0.1418,-0.6004);
	glPopMatrix();
}

void special_function(int tecla, int x, int y) {
	switch (tecla) {
		case GLUT_KEY_RIGHT:
			tx += 0.025;
			theta += 5;
			break;
			
		case GLUT_KEY_LEFT:
			tx -= 0.025;
			theta -= 5;
			break;
	}
	glutPostRedisplay();
}

void desenha() {
	glClearColor(0.2,0.8,0.9,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
		
	car();
	
	glFlush();
}

int main(int argc, char **argv) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(400,400);
	glutInit(&argc, argv);
	glutCreateWindow("Car");
	glutDisplayFunc(desenha);
	glutSpecialFunc(special_function);
	glutMainLoop();
	return 0;
}
