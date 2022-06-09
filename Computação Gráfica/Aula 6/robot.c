#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float theta = 0.0;
float PI = 3.1415;

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

void circulo_rotation(float r, float incX, float incY, float pmX, float pmY) {
	int i;
	float angulo = 0.0;
	glBegin(GL_POLYGON);
		for(i = 0; i <= 50; i++) {
			angulo = 2 * PI * i / 50.0;
			float x = r*cos(angulo)+incX;
			float y = r*sin(angulo)+incY;
			float rotationXr = pmX-pmX*cos(theta) + pmY*sin(theta);
			float rotationYr = pmY-pmY*cos(theta) - pmX*sin(theta);			
			glVertex2f(x*cos(theta) - y*sin(theta) + rotationXr, x*sin(theta) + y*cos(theta) + rotationYr);
		}
	glEnd();
}

void cabeca() {
	glColor3f(0.3,0.4,0.4);
	glBegin(GL_POLYGON);
		glVertex2f(-0.4,0.5); 
		glVertex2f(-0.4,0.3); 
		glVertex2f(0.4,0.3);
		glVertex2f(0.4,0.5);    
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex2f(-0.1,0.05); 
		glVertex2f(-0.1,0.2); 
		glVertex2f(0.1,0.2);   
		glVertex2f(0.1,0.05);  
	glEnd();
	
	glLineWidth(2.5f);
	glBegin(GL_LINES);
		glVertex2f(-0.35,0.7672);
		glVertex2f(-0.35,0.5);
	glEnd();
	
	glBegin(GL_LINES);
		glVertex2f(0.35,0.7672);
		glVertex2f(0.35,0.5);
	glEnd();
	
	glColor3f(0.3,0.5,0.6);
	glBegin(GL_POLYGON);
		glVertex2f(-0.3,0.6); 
		glVertex2f(-0.3,0.2); 
		glVertex2f(0.3,0.2);  
		glVertex2f(0.3,0.6);  
	glEnd();
	
	circulo(0.03,-0.35,0.7621);
	circulo(0.03,0.35,0.7621);
	
	glColor3f(0.1,0.8,0.4);
	circulo(0.1,0.15,0.4);
	circulo(0.1,-0.15,0.4);
	
	glBegin(GL_POLYGON);
		glVertex2f(-0.05,0.25); 
		glVertex2f(-0.05,0.22); 
		glVertex2f(0.05,0.22);  
		glVertex2f(0.05,0.25); 
	glEnd();
}

void torax() {
	glColor3f(0.3,0.5,0.6);
	glBegin(GL_POLYGON);
		glVertex2f(-0.45,0.05); 
		glVertex2f(-0.45,-0.5); 
		glVertex2f(0.45,-0.5);  
		glVertex2f(0.45,0.05);  
	glEnd();
	
	glColor3f(0.1,0.8,0.4);
	glBegin(GL_POLYGON);
		glVertex2f(-0.2,-0.1); 
		glVertex2f(-0.2,-0.3); 
		glVertex2f(0.2,-0.3);  
		glVertex2f(0.2,-0.1);  
	glEnd();
	
	glColor3f(0.8,0.0,0.0);
	circulo(0.0422,-0.1589,-0.3614);
	glColor3f(1.0,0.8,0.0);
	circulo(0.0422,-0.0053,-0.3614);
	glColor3f(0.0,0.0,0.8);
	circulo(0.0422,0.1589,-0.3614);
}

void braco_1() {
	float pmX = -0.4501;
	float pmY = -0.0376;	
	float rotationXr = pmX-pmX*cos(theta) + pmY*sin(theta);
	float rotationYr = pmY-pmY*cos(theta) - pmX*sin(theta);
	
	glBegin(GL_POLYGON);
		glVertex2f(-0.8*cos(theta)+0.2*sin(theta) + rotationXr, -0.8*sin(theta)-0.2*cos(theta) + rotationYr);
		glVertex2f(-0.7*cos(theta)+0.3*sin(theta) + rotationXr, -0.7*sin(theta)-0.3*cos(theta) + rotationYr);
		glVertex2f(-0.35*cos(theta)-0.05*sin(theta) + rotationXr, -0.35*sin(theta)-0.05*cos(theta) + rotationYr);
		glVertex2f(-0.45*cos(theta)-0.05*sin(theta) + rotationXr, -0.45*sin(theta)+0.05*cos(theta) + rotationYr);
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex2f(-0.8*cos(theta)+0.2*sin(theta) + rotationXr, -0.8*sin(theta)-0.2*cos(theta) + rotationYr);
		glVertex2f(-0.8*cos(theta)+0.6*sin(theta) + rotationXr, -0.8*sin(theta)-0.6*cos(theta) + rotationYr);
		glVertex2f(-0.7*cos(theta)+0.6*sin(theta) + rotationXr, -0.7*sin(theta)-0.6*cos(theta) + rotationYr);
		glVertex2f(-0.7*cos(theta)+0.2*sin(theta) + rotationXr, -0.7*sin(theta)-0.2*cos(theta) + rotationYr);
	glEnd();
}

void braco_2() {
	float pmX = 0.4501;
	float pmY = 0.0376;	
	float rotationXr = pmX-pmX*cos(theta) + pmY*sin(theta);
	float rotationYr = pmY-pmY*cos(theta) - pmX*sin(theta);
	
	glBegin(GL_POLYGON);
		glVertex2f(0.8*cos(theta)+0.2*sin(theta) + rotationXr, 0.8*sin(theta)-0.2*cos(theta) + rotationYr);
		glVertex2f(0.7*cos(theta)+0.3*sin(theta) + rotationXr, 0.7*sin(theta)-0.3*cos(theta) + rotationYr);
		glVertex2f(0.35*cos(theta)-0.05*sin(theta) + rotationXr, 0.35*sin(theta)-0.05*cos(theta) + rotationYr);
		glVertex2f(0.45*cos(theta)-0.05*sin(theta) + rotationXr, 0.45*sin(theta)+0.05*cos(theta) + rotationYr);
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex2f(0.8*cos(theta)+0.2*sin(theta) + rotationXr, 0.8*sin(theta)-0.2*cos(theta) + rotationYr);
		glVertex2f(0.8*cos(theta)+0.6*sin(theta) + rotationXr, 0.8*sin(theta)-0.6*cos(theta) + rotationYr);
		glVertex2f(0.7*cos(theta)+0.6*sin(theta) + rotationXr, 0.7*sin(theta)-0.6*cos(theta) + rotationYr);
		glVertex2f(0.7*cos(theta)+0.2*sin(theta) + rotationXr, 0.7*sin(theta)-0.2*cos(theta) + rotationYr);
	glEnd();
}

void bracos() {
	glColor3f(0.3,0.5,0.6);
	braco_1();
	braco_2();
	
	glColor3f(0.3,0.4,0.4);
	circulo(0.09,-0.4501,-0.0376);
	circulo_rotation(0.09,-0.75,-0.25,-0.4501,-0.0376);
	circulo(0.09,0.4501,-0.0376);
	circulo_rotation(0.09,0.75,-0.25,0.4501,-0.0376);
}

void pernas() {
	glColor3f(0.3,0.5,0.6);
	float pmX = -0.15;
	float pmY = -0.5;	
	float rotationXr = pmX-pmX*cos(theta) + pmY*sin(theta);
	float rotationYr = pmY-pmY*cos(theta) - pmX*sin(theta);
	
	glBegin(GL_POLYGON);
		glVertex2f(-0.22*cos(theta)+0.5*sin(theta) + rotationXr, -0.22*sin(theta)-0.5*cos(theta) + rotationYr);
		glVertex2f(-0.22*cos(theta)+0.9*sin(theta) + rotationXr, -0.22*sin(theta)-0.9*cos(theta) + rotationYr);
		glVertex2f(-0.08*cos(theta)+0.9*sin(theta) + rotationXr, -0.08*sin(theta)-0.9*cos(theta) + rotationYr);
		glVertex2f(-0.08*cos(theta)+0.5*sin(theta) + rotationXr, -0.08*sin(theta)-0.5*cos(theta) + rotationYr);
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex2f(0.22*cos(theta)+0.5*sin(theta) + rotationXr, 0.22*sin(theta)-0.5*cos(theta) + rotationYr);
		glVertex2f(0.22*cos(theta)+0.9*sin(theta) + rotationXr, 0.22*sin(theta)-0.9*cos(theta) + rotationYr);
		glVertex2f(0.08*cos(theta)+0.9*sin(theta) + rotationXr, 0.08*sin(theta)-0.9*cos(theta) + rotationYr);
		glVertex2f(0.08*cos(theta)+0.5*sin(theta) + rotationXr, 0.08*sin(theta)-0.5*cos(theta) + rotationYr);
	glEnd();
	
	glColor3f(0.3,0.4,0.4);
	circulo(0.09,-0.15,-0.5);
	circulo(0.09,0.15,-0.5);
}

void desenha() {
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	cabeca();
	bracos();
	pernas();
	torax();
	
	glFlush();
}

void special_function(int tecla, int x, int y) {
	switch (tecla) {
		case GLUT_KEY_RIGHT:
			if (theta <= 0.2) theta += 0.005;
			break;
			
		case GLUT_KEY_LEFT:
			if (theta >= -0.2) theta -= 0.005;
			break;
	}
	glutPostRedisplay();
}

int main(int argc, char **argv) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(400,400);
	glutInit(&argc, argv);
	glutCreateWindow("Robot");
	glutDisplayFunc(desenha);
	glutSpecialFunc(special_function);
	glutMainLoop();
	return 0;
}

