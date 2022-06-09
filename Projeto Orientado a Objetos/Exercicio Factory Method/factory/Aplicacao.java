package factory;

public class Aplicacao {
	public static void main(String[] args) {
		FiguraFactory figuraFactory = new FiguraFactory();
		double x = 4;
		
		System.out.println("Área circulo = " + figuraFactory.getFigura(x, "Circulo").area());
		System.out.println("Área quadrado = " + figuraFactory.getFigura(x, "Quadrado").area());
		System.out.println("Área triângulo = " + figuraFactory.getFigura(x, "Triangulo").area());	
	}
}
