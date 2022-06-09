package abstract_factory;

public class TrianguloB implements Triangulo {
	private Ponto A;
	private Ponto B;
	private Ponto C;
	
	public TrianguloB(Ponto A, Ponto B, Ponto C) {
		this.A = A;
		this.B = B;
		this.C = C;
	}
	
	public double getAltura() {
		return ((( Math.abs((A.getX() - A.getY())) * Math.abs((B.getX() - B.getY()))) * Math.sqrt(3)) / 4);
	}
	
	public double area() {
		return (Math.abs((C.getX() - C.getY())) * this.getAltura()) / 2;
	}
	
	public String toString() {
		return "Triangulo B: area = " + area();
	}
}
