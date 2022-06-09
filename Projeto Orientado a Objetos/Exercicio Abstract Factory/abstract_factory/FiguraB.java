package abstract_factory;

public class FiguraB implements AbstractFactory {
	 
	@Override
	public Circulo getCirculo(Ponto A, double raio) {
		return new CirculoB(A, raio);
	}

	@Override
	public Retangulo getRetangulo(Ponto A, Ponto B) {
		return new RetanguloB(A, B);
	}

	@Override
	public Triangulo getTriangulo(Ponto A, Ponto B, Ponto C) {
		return new TrianguloB(A, B, C);
	}
}
