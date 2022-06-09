package aula_6b;
import java.util.Scanner;

public class Poligonos {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int tipo;
		double lado, area, perimetro;
		double[] lados = new double[3]; 
		
		do {
			System.out.println("Escolha uma figura:\n[1] Quadrado\n[2] Triangulo");
			tipo = scan.nextInt();
			if(tipo == 1) {
				System.out.println("Informe o tamanho do lado do quadrado...");
				lado = scan.nextDouble();
				area = lado*lado;
				perimetro = 4*lado;
				System.out.println("Area " + area + "\nPerimetro " + perimetro);
			}
			else if(tipo == 2) {
				System.out.println("Informe o tamanho dos lados do triagulo...");
				for(int i = 0; i < 3; i++) {
					lados[i] = scan.nextDouble();
				}
				System.out.println(lados[0]);
				System.out.println(lados[1]);
				System.out.println(lados[2]);
				if(lados[0] == lados[1] && lados[1] == lados[2]) {
					System.out.println("Triangulo equilatero");
				}
				else if((lados[0] == lados[1]) || (lados[1] == lados[2]) || (lados[2] == lados[0])) {
					System.out.println("Triangulo isósceles");
				}
				else {
					System.out.println("Triangulo Escaleno");
				}
			}
			else System.err.println("Comando inválido");
		
		}while(tipo != 1 && tipo != 2);
	
	}
}
