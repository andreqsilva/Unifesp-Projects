package factory;

public class Quadrado implements Figura {
	private double lado;
	
	public double getLado() {
		return this.lado;
	}
	
	public void setLado(double base) {
		this.lado = base;
	}
	
	public double area() {
		return lado * lado;
	}
}
