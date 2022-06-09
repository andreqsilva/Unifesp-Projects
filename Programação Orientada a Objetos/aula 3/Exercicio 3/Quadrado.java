package aula3;
import java.lang.Math;

public class Quadrado {
	private double lado;
	public Quadrado() {}
	public Quadrado(double l) {
		this.lado = l;
	}
	
	public double area() {
		return (this.lado*this.lado);
	}
	
	public void aumenta_lado(double x) {
		this.lado += x;
	}
	
	public double getLado() {
		return this.lado;
	}
	
	public void setLado(double l) {
		this.lado = l;
	}
	
	public static void main(String args[]) {
		Quadrado q1 = new Quadrado(2);
		
		System.out.println(q1.area());
		q1.aumenta_lado(3);
		System.out.println(q1.area());
		
		int i;
		double soma = 0;
		
		for(i = 0; i < 10; i++) {
			double a = Math.random();
			Quadrado q = new Quadrado(a);
			soma += q.area();
		}	
		System.out.println("Soma das areas: " + soma);
	}
}
