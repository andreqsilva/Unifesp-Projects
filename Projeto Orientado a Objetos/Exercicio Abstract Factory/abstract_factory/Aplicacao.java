package abstract_factory;

public class Aplicacao {
	public static void main(String[] args) {
		Ponto A = new Ponto(4,2);
		Ponto B = new Ponto(1,3);
		Ponto C = new Ponto(3,5);
		
		FiguraA figuraA = new FiguraA();
		Circulo circuloA = figuraA.getCirculo(A,2);
		Retangulo retanguloA = figuraA.getRetangulo(A,B);
		Triangulo trianguloA = figuraA.getTriangulo(A,B,C);
		System.out.println(circuloA.toString() + "\n" + retanguloA.toString() + 
											"\n" + trianguloA.toString() + "\n");
		
		FiguraB figuraB = new FiguraB();
		Circulo circuloB = figuraB.getCirculo(A,2);
		Retangulo retanguloB = figuraB.getRetangulo(B,C);
		Triangulo trianguloB = figuraB.getTriangulo(A,B,C);
		System.out.println(circuloB.toString() + "\n" + retanguloB.toString() + 
											"\n" + trianguloB.toString());
	}
}
