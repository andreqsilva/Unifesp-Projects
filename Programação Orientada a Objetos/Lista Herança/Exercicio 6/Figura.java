package figuras;

public abstract class Figura {
	public double getArea() {
		return 0.0;
	}
	public abstract String toString();
	
	public static void main(String args[]) {
		Quadrado quadrado = new Quadrado(4);
		TrianguloRetangulo triangulo = new TrianguloRetangulo(9,2);
		Losango losango = new Losango(3,4);
		
		//System.out.println(quadrado.toString());
		//System.out.println(quadrado.getArea());
		
		System.out.println(triangulo.toString());
		System.out.println("Area = " + triangulo.getArea());
		
		System.out.println(losango.toString());
		System.out.println("Area = " + losango.getArea());
		
	}
	
}

class Circulo extends Figura {
	private double raio;	
	public Circulo(double _raio) {
		super();
		this.raio = _raio;
	}
	
	public double getRaio() {
		return this.raio;
	}
	
	@Override
	public double getArea() {
		return Math.PI*this.raio*this.raio;
	}
	
	@Override
	public String toString() {
		return "Raio = " + getRaio();
	}
}

class Paralelogramo extends Figura {
	private double base;
	private double altura;
	
	public Paralelogramo(double _base, double _altura) {
		super();
		this.base = _base;
		this.altura = _altura;
	}
	
	public double getBase() {
		return this.base;
	}
	
	public double getAltura() {
		return this.altura;
	}
	
	@Override
	public double getArea() {
		return this.base*this.altura;
	}
	
	@Override
	public String toString() {
		return "Base = " + this.getBase() + "\nAltura = " + this.getAltura();
	}
}

class Losango extends Paralelogramo {
	public Losango(double _base, double _altura) {
		super(_base,_altura);
	}
	
	@Override
	public double getArea() {
		return super.getBase()*super.getAltura()/2;
	}
	
	@Override
	public String toString() {
		return super.toString();
	}
}

class Retangulo extends Figura {
	private double base;
	private double altura;
	
	public Retangulo(double _base, double _altura) {
		super();
		this.base = _base;
		this.altura = _altura;
	}
	
	public double getBase() {
		return this.base;
	}
	
	public double getAltura() {
		return this.altura;
	}
	
	@Override
	public double getArea() {
		return this.base*this.altura;
	}
	
	@Override
	public String toString() {
		return "Base = " + this.getBase() + "\nAltura = " + this.getAltura();
	}
}

class Quadrado extends Retangulo {
	public Quadrado(double lado) {
		super(lado,lado);
	}
	
	@Override
	public double getArea() {
		return super.getArea();
	}
	
	@Override
	public String toString() {
		return "Lado: " + super.getBase();
	}
}

class Triangulo extends Figura {
	private double base;
	private double altura;
	
	public Triangulo(double _base, double _altura) {
		super();
		this.base = _base;
		this.altura = _altura;
	}
	
	public double getBase() {
		return this.base;
	}
	
	public double getAltura() {
		return this.altura;
	}
	
	@Override
	public double getArea() {
		return this.base*this.altura/2;
	}
	
	@Override
	public String toString() {
		return "Base = " + this.getBase() + "\nAltura = " + this.getAltura();
	}
}

class TrianguloRetangulo extends Triangulo {
	public TrianguloRetangulo(double _base, double _altura) {
		super(_base, _altura);
	}
	
	@Override
	public double getArea() {
		return super.getArea();
	}
	
	@Override
	public String toString() {
		return super.toString();
	}
}
