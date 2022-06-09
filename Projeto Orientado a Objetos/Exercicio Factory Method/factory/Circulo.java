package factory;
import java.lang.Math;

public class Circulo implements Figura {
	private double raio;
	
	public double getRaio() {
		return this.raio;
	}
	
	public void setRaio(double raio) {
		this.raio = raio;
	}
	
	public double area() {
		return Math.PI * (raio * raio);
	}
}
