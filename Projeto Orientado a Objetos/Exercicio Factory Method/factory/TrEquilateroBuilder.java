package factory;

public class TrEquilateroBuilder extends Construtor {
	private TrEquilatero triangulo;
	
	public TrEquilateroBuilder() {
		triangulo = new TrEquilatero();
	}
	
	@Override
	public TrEquilateroBuilder criaFigura(double lado) {
		triangulo.setLado(lado);
		return this;
	}
	
	@Override
	public TrEquilatero get() {
		return this.triangulo;
	}
}

