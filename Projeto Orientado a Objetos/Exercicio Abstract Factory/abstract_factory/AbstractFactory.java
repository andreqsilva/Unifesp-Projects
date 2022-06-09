package abstract_factory;

public interface AbstractFactory{
	public Circulo getCirculo(Ponto A, double raio);
	public Retangulo getRetangulo(Ponto A, Ponto B);
	public Triangulo getTriangulo(Ponto A, Ponto B, Ponto C);
}
