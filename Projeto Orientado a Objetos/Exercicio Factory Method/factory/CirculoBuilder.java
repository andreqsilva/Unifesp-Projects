package factory;

public class CirculoBuilder extends Construtor {
	private Circulo circulo;
	
	public CirculoBuilder() {
		circulo = new Circulo();
	}
	
	@Override
	public CirculoBuilder criaFigura(double raio) {
		circulo.setRaio(raio);
		return this;
	}
	
	@Override
	public Circulo get() {
		return this.circulo;
	}
}
