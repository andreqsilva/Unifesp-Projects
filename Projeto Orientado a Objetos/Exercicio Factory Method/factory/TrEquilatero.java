package factory;

public class TrEquilatero implements Figura {
	private double lado;
	
	private double getAltura() {
		return (((lado * lado) * Math.sqrt(3)) / 4);
	}
	
	public double getLado() {
		return this.lado;
	}
	
	public void setLado(double lado) {
		this.lado = lado;
	}
	
	public double area() {
		return (lado * this.getAltura()) / 2;
	}
}
