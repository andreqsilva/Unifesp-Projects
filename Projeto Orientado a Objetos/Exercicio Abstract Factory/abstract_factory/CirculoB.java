package abstract_factory;

public class CirculoB implements Circulo {
	private Ponto ponto;
	private double raio;
	
	public CirculoB(Ponto ponto, double raio) {
		this.ponto = ponto;
		this.raio = raio;
	}
	
	public double area() {
		return Math.PI * (raio * raio);
	}
	
	public String toString() {
		return "Circulo B: area = " + this.area();
	}
}
