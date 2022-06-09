#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float PI = 3.1415;
float theta = 0.0;
int variaTimer = 100;
int opcao;

void init() {
	glClearColor(0.0,0.0,0.0,0.0); 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glOrtho(-10.0,10.0,-10.0,10.0,-10.0,10.0);
	glPushMatrix();
}

void circulo(float r) {
	int i;
	float angulo = 0.0;
	glBegin(GL_POLYGON);
		for(i = 0; i <= 50; i++) {
			angulo = 2 * PI * i / 50.0;
			glVertex2f(r*cos(angulo), r*sin(angulo));
		}
	glEnd();
}

void semi_circulo(float r) {
	int i;
	float angulo = 0.0;
	glBegin(GL_POLYGON);
		for(i = 0; i <= 50; i++) {
			angulo = 2 * PI * i / 100.0;
			glVertex2f(r*cos(angulo), r*sin(angulo));
		}
	glEnd();
}

void retangulo() {
	glBegin(GL_POLYGON);
		glVertex2f(-0.3, 0);
		glVertex2f(0.3, 0);
		glVertex2f(0.3, -10.0);
		glVertex2f(-0.3, -10.0);
	glEnd();
}

void timerFunc(int value) {
	switch (opcao) {
		case 1: 
			if (variaTimer < 100)
				theta += 5; 
			break;
		default:
			break;
	}
	glutPostRedisplay();
	glutTimerFunc(variaTimer,timerFunc,1);
}

void rotacoes(int tecla, int x, int y) {
	switch (tecla) {
		case GLUT_KEY_RIGHT:
			opcao = 1;
			if (variaTimer > 5)
				variaTimer -= 5;
			break;
			
		case GLUT_KEY_LEFT:
			if (variaTimer < 100)
				variaTimer += 5;
			break;
	}
	glutPostRedisplay();
}

void mouseFunc(int button, int state, int x, int y) {
	switch (button) {
		case GLUT_LEFT_BUTTON:
			if (state == GLUT_DOWN) {
				opcao = 1;
				if (variaTimer > 5) variaTimer -= 5;
			break;
		}
		
		case GLUT_RIGHT_BUTTON:
			if (state == GLUT_DOWN) 
				if (variaTimer < 100) variaTimer += 5;
			break;
	}
	glutPostRedisplay();
}

void desenha() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPopMatrix();
	glPushMatrix();
	
	glPushMatrix();
	glTranslatef(0.0,2.0,0.0);
	
	glColor3f(0.4,0.3,0.1);
	retangulo();
	
	glRotatef(theta,0.0,0.0,1.0);
	
	glColor3f(1.0,0.0,0.0);
	glPushMatrix();
	glTranslatef(0.0,3.0,0.0);
	glRotatef(90,0.0,0.0,1.0);
	semi_circulo(3);
	glPopMatrix();
	
	glColor3f(1.0,1.0,0.0);
	glPushMatrix();
	glTranslatef(0.0,-3.0,0.0);
	glRotatef(-90,0.0,0.0,1.0);
	semi_circulo(3);
	glPopMatrix();
	
	glColor3f(0.0,0.0,1.0);
	glPushMatrix();
	glTranslatef(3.0,0.0,0.0);
	semi_circulo(3);
	glPopMatrix();
	
	glColor3f(0.0,1.0,0.0);
	glPushMatrix();
	glTranslatef(-3.0,0.0,0.0);
	glRotatef(180,0.0,0.0,1.0);
	semi_circulo(3);	
	glPopMatrix();
	
	glColor3f(1.0,1.0,1.0);
	circulo(0.6);
	glPopMatrix();
	
	glFlush();
}

int main(int argc, char **argv) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(600,600);
	glutInit(&argc, argv);
	glutCreateWindow("Catavento");
	glutDisplayFunc(desenha);
	glutSpecialFunc(rotacoes);
	glutMouseFunc(mouseFunc);
	glutTimerFunc(variaTimer,timerFunc,1);
	init();
	glutMainLoop();
	return 0;
}
