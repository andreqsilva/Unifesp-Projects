package factory;

public class QuadradoBuilder extends Construtor {
	private Quadrado quadrado;
	
	public QuadradoBuilder() {
		quadrado = new Quadrado();
	}
	
	@Override
	public QuadradoBuilder criaFigura(double lado) {
		quadrado.setLado(lado);
		return this;
	}
	
	@Override
	public Quadrado get() {
		return this.quadrado;
	}
}
