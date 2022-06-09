package abstract_factory;
import java.lang.Math;

public class CirculoA implements Circulo {
	private Ponto ponto;
	private double raio;
	
	public CirculoA(Ponto ponto, double raio) {
		this.ponto = ponto;
		this.raio = raio;
	}
	
	public double area() {
		return Math.PI * (raio * raio);
	}
	
	public String toString() {
		return "Circulo A: area = " + this.area();
	}
}
