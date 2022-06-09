package abstract_factory;

public class RetanguloA implements Retangulo {
	private Ponto pontoA;
	private Ponto pontoB;
	
	public RetanguloA(Ponto A, Ponto B) {
		this.pontoA = A;
		this.pontoB = B;
	}
	
	@Override
	public double area() {
		return Math.abs((pontoA.getX() - pontoA.getY())) * Math.abs((pontoB.getX() - pontoB.getY()));
	}
	
	@Override
	public String toString() {
		return "Retangulo A: area = " + this.area();
	}
}
