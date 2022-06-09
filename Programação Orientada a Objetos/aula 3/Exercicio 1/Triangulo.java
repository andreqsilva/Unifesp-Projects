package aula3;

public class Triangulo {
	private float base;
	private float altura;
	public Triangulo() {
		this.base = 12;
		this.altura = 5;
	}
	public Triangulo(float b, float a) {
		this.base = b;
		this.altura = a;
	}
	
	public void area() {
		double a = (this.base*this.altura)/2;
		System.out.println(a);
	}
	
	public void mostra() {
		System.out.println("Base: " + this.base);
		System.out.println("Altura: " + this.altura);
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
		Triangulo t1 = new Triangulo();
		Triangulo t2 = new Triangulo(4,8);
		
		t1.mostra();
		t1.area();
		System.out.println(t2.getBase());
		t2.mostra();
	}
}
