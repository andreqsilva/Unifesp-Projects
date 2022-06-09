#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RETA 0
#define TRIANGULO 1

/* 1/número de pixels => 1/400 = 0.005
   pontoX = (x * 0.005) - 1
   pontoY = ((y * 0.005) - 1) * (-1)
*/

float ponto_0[2] = {0,0};
float ponto_1[2] = {0,0};
float ponto_2[2] = {0,0};
float red = 0.0;
float green = 0.0;
float blue = 1.0;
int click = 0;
int figura = RETA;

void linha() {	
	glColor3f(red,green,blue);
	glLineWidth(0.5f);  //tamaho da linha
	glBegin(GL_LINES);
		glVertex2f(ponto_0[0],ponto_0[1]);
		glVertex2f(ponto_1[0],ponto_1[1]);
	glEnd();
}

void triangulo() {
	glColor3f(red,green,blue);
	glBegin(GL_TRIANGLES);
		glVertex2f(ponto_0[0],ponto_0[1]);
		glVertex2f(ponto_1[0],ponto_1[1]);
		glVertex2f(ponto_2[0],ponto_2[1]);
	glEnd();
}

void zera_pontos() {
	int i;
	for (i = 0; i < 2; i++) {
		ponto_0[i] = 0;
		ponto_1[i] = 0;
		ponto_2[i] = 0;
	}
}

void desenha() {
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	if (figura == RETA) {
		if (click == 2 || click == 0) {
			linha();
			click = 0;		
		}
	}
	else if (figura == TRIANGULO) {
		if (click == 3 || click == 0) {
			triangulo();
			click = 0;
		}
		
	}	
	glFlush();
}

void mouse(int botao, int estado, int x, int y) {
	switch (botao) {
		case GLUT_LEFT_BUTTON:
			if (estado == GLUT_DOWN) {
				click++;
				if (click == 1) {
					ponto_0[0] = (x * 0.005) - 1;	
					ponto_0[1] = ((y * 0.005) - 1) * -1;
				}
				else if (click == 2) {
					ponto_1[0] = (x * 0.005) - 1;	
					ponto_1[1] = ((y * 0.005) - 1) * -1;
					if (figura == RETA) click = 0;
				}
				
				else if (click == 3) {
					ponto_2[0] = (x * 0.005) - 1;	
					ponto_2[1] = ((y * 0.005) - 1) * -1;	
					click = 0;			
				}
			}
	}
	glutPostRedisplay();
}

void teclado(unsigned char tecla, int x, int y) {
	switch (tecla) {
		case 'r':
			figura = RETA;
			click = 0;
			zera_pontos();
			break;
		case 'R':
			figura = RETA;
			click = 0;
			zera_pontos();
			break;
		case 't':
			figura = TRIANGULO;
			click = 0;
			zera_pontos();
			break;
		case 'T':
			figura = TRIANGULO;
			click = 0;
			zera_pontos();
			break;
				
		case '0':	//vermelho
			red = 1.0;
			green = 0.0;
			blue = 0.0;
			break;
		case '1':	//verde
			red = 0.0;
			green = 1.0;
			blue = 0.0;
			break;
		case '2':	//azul
			red = 0.0;
			green = 0.0;
			blue = 1.0;
			break;
		case '3':	//amarelo
			red = 1.0;
			green = 1.0;
			blue = 0.0;
			break;
		case '4':	//roxo
			red = 1.0;
			green = 0.0;
			blue = 1.0;
			break;
		case '5':	//ciano
			red = 0.0;
			green = 1.0;
			blue = 1.0;
			break;
		case '6':	//laranja
			red = 1.0;
			green = 0.5;
			blue = 0.0;
			break;
		case '7':	//marrom
			red = 0.5;
			green = 0.2;
			blue = 0.0;
			break;
		case '8':	//rosa
			red = 1.0;
			green = 0.2;
			blue = 0.5;
			break;
		case '9':	//branco
			red = 1.0;
			green = 1.0;
			blue = 1.0;
			break;
	}
	glutPostRedisplay();
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Pontos");
	glutDisplayFunc(desenha);
	glutMouseFunc(mouse);
	glutKeyboardFunc(teclado);
	glutMainLoop();
	return 0;
}
