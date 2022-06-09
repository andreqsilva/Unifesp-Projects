package abstract_factory;

public class FiguraA implements AbstractFactory {

	@Override
	public Circulo getCirculo(Ponto A, double raio) {
		return new CirculoA(A, raio);
	}

	@Override
	public Retangulo getRetangulo(Ponto A, Ponto B) {
		return new RetanguloA(A, B);
	}

	@Override
	public Triangulo getTriangulo(Ponto A, Ponto B, Ponto C) {
		return new TrianguloA(A, B, C);
	}
}
