package aula3;

public class Retangulo {
	private float base;
	private float altura;
	public Retangulo() {}
	public Retangulo(float b, float a) {
		this.base = b;
		this.altura = a;
	}
	
	public void area() {
		System.out.println(this.base*this.altura);
	}
	
	public void perimetro() {
		System.out.println((2*this.base) + (2*this.altura));
	}
	
	public void relacao() {
		System.out.println(this.base/this.altura);
	}
	
	public void quadrado() {
		if(this.base == this.altura) {
			System.out.println("É quadrado!");
		}
		else System.out.println("Não é um quadrado");
	}
	
	public float getBase() {
		return this.base;
	}
	
	public float getAltura() {
		return this.altura;
	}
	
	public void setBase(float b) {
		this.base = b;
	}
	
	public void setAltura(float a) {
		this.altura = a;
	}
	
	public static void main(String args[]) {
		Retangulo r1 = new Retangulo(12,5);
		Retangulo r2 = new Retangulo(5,5);
		
		r1.area();
		r1.perimetro();
		r1.relacao();
		r1.quadrado();
		System.out.println("Base: " + r1.getBase());
		System.out.println("Altura: " + r1.getAltura());
	}
}
