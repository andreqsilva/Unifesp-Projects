/* Implementação de uma calculadora */

#include <stdio.h>
#include <math.h>

double memoria[5];
int i = 0;
int main(){
double valor_2(double x, double y);
double valor_1(double x);
double soma(double x, double y);
double subtracao(double x, double y);
double multiplicacao(double x, double y);
double divisao(double x, double y);
double raiz_quadrada(double x);
double potencia(double x, double y);
double seno(double x);
double cosseno(double x);
double logaritmo(double x);
double fatorial(double x);
void historico_memoria(double r);
void historico(void);
void comandos(void);
int c = 12, i;
double resultado, x, y;

while(c != 0)
    {
    switch(c)
    {
    case 1:
    printf("Valores de x e y: ");
    scanf("%lf %lf", &x, &y);
    resultado = soma(x,y);
    printf("Resultado = %.2lf\n",resultado);
    historico_memoria(resultado);
    break;
    case 2:
    printf("Valores de x e y: ");
    scanf("%lf %lf", &x, &y);
    resultado = subtracao(x,y);
    printf("Resultado = %.2lf\n",resultado);
    historico_memoria(resultado);
    break;
    case 3:
    printf("Valores de x e y: ");
    scanf("%lf %lf", &x, &y);
    if(y == 0)
        printf("Divisão indefinida\n");
    else
    {
    resultado = divisao(x,y);
    printf("Resultado = %.2lf\n",resultado);
    historico_memoria(resultado);
    }
    break;
    case 4:
    printf("Valores de x e y: ");
    scanf("%lf %lf", &x, &y);
    resultado = multiplicacao(x,y);
    printf("Resultado = %.2lf\n",resultado);
    historico_memoria(resultado);
    break;
    case 5:
    printf("Valor de x: ");
    scanf("%lf", &x);
    if(x < 0)
        printf("Não existe raiz quadrada de números negativos\n");
    else
    {
    resultado = raiz_quadrada(x);
    printf("Resultado = %.2lf\n",resultado);
    historico_memoria(resultado);
    }
    break;
    case 6:
    printf("Valores de x e y: ");
    scanf("%lf %lf", &x, &y);
    if (x == 0 && y == 0)
        printf("Indefinido\n");
    else
    {
    resultado = potencia(x,y);
    printf("Resultado = %.2lf\n",resultado);
    historico_memoria(resultado);
    }
    break;
    case 7:
    printf("Valor de x: ");
    scanf("%lf %lf", &x, &y);
    resultado = seno(x);
    printf("Resultado = %.4lf\n",resultado);;
    historico_memoria(resultado);
    break;
    case 8:
    printf("Valor de x: ");
    scanf("%lf", &x);
    resultado = cosseno(x);
    printf("Resultado = %.4lf\n",resultado);
    historico_memoria(resultado);
    break;
    case 9:
    printf("Valor de ln x: ");
    scanf("%lf", &x);
    if(x > 0)
        {
        resultado = logaritmo(x);
        printf("Resultado = %.3lf\n",resultado);
        historico_memoria(resultado);    
        }
    else
    {
    printf("Só existe logaritmo de números positivos maiores que 0\n");
    }
    break;
    case 10:
    printf("Valor de x!: ");
    scanf("%lf", &x);
    if(x < 0)
        printf("Não existe fatorial de números negativos\n");
    else
    {
    resultado = fatorial(x);
    printf("Resultado = %.2lf\n",resultado);
    historico_memoria(resultado);
    }
    break;        
    case 11:
    historico();
    break;
    case 12:
    comandos();
    break;
    default:
    printf("Comando errado. Tente novamente\n");
    }
    printf("O que deseja fazer? ");
    scanf("%d", &c);
    }
    printf("Desligando...");
}
void historico_memoria(double r)
{
    memoria[i] = r;
    i++;
    if(i == 5)
        i = 0;
}    
double soma(double x, double y)
{
    double resultado;
    resultado = (x+y);
    return resultado;
}
double subtracao(double x, double y)
{
    double resultado;
    resultado = (x-y);
    return resultado;
}
double divisao(double x, double y)
{
    double resultado;
    resultado = (x/y);
    return resultado;
} 
double multiplicacao(double x, double y)
{
    double resultado;
    resultado = (x*y);
    return resultado;
}
double raiz_quadrada(double x)
{
    double resultado;
    resultado = sqrt(x);
    return resultado;
}
double potencia(double x, double y)
{
    double resultado;
    resultado = pow(x,y);
    return resultado;
}
double seno(double x)
{
    double resultado;
    resultado = sin(x);
    return resultado;
}
double cosseno(double x)
{
    double resultado;
    resultado = cos(x);
    return resultado;
}
double logaritmo(double x)
{
    double resultado;
    resultado = log(x);
    return resultado;
}
double fatorial(double x)
{
    double resultado;
    for(resultado = 1;x > 1;x--)
    {
        resultado = (resultado*x);
    }
    return resultado;
}
void historico(void)
{
    printf("Histórico:\n");
    for(int i = 0;i < 5;i++)
    {
        printf("|%.2lf|\n", memoria[i]);
    }
}
void comandos(void)
{
    printf("***************************************\n");
    printf("0 - Desligar a calculadora\n"
    "1 - adição (x,y)\n"
    "2 - subtração (x,y)\n"
    "3 - divisão (x,y)\n"
    "4 - multiplicação (x,y)\n"
    "5 - raiz quadrada (x)\n"
    "6 - potenciação(x,y)\n"
    "7 - sen(x)\n"
    "8 - cos(x)\n"
    "9 - logaritmo (ln x)\n"
    "10 - fatorial (x!)\n"
    "11 - historico das 5 últimas operações\n"
    "12 - Ver os comandos da calculadora\n");
    printf("***************************************\n");
}

