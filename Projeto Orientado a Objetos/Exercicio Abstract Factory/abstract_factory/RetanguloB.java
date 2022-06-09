package abstract_factory;

public class RetanguloB implements Retangulo {
	private Ponto pontoA;
	private Ponto pontoB;
	
	public RetanguloB(Ponto A, Ponto B) {
		this.pontoA = A;
		this.pontoB = B;
	}
	
	@Override
	public double area() {
		return Math.abs((pontoA.getX() - pontoA.getY())) * Math.abs((pontoB.getX() - pontoB.getY()));
	}
	
	@Override
	public String toString() {
		return "Retangulo B: area =  " + this.area();
	}
}
