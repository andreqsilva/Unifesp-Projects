package aula3;

public class Carro {
	private String marca;
	private String modelo;
	private String placa;
	private boolean ligado;
	private int vezesAcelerou;
	private int vezesFreou;
	private int vezesLigou;
	public Carro(String m, String mo, String p) {
		this.vezesAcelerou = 0;
		this.vezesFreou = 0;
		this.vezesLigou = 0;
		this.marca = m;
		this.modelo = mo;
		this.placa = p;
	}
	
	public void ligar() {
		if(!ligado) {
			System.out.println("Ligando carro...");
			this.ligado = true;
			this.vezesLigou++;
		}
		else System.out.println("O carro já está ligado");
	}
	
	public void desligar() {
		if(ligado) {
			System.out.println("Desligando carro");
			this.ligado = false;
		}
		else System.out.println("O carro já está desligado");
	}
	
	public void acelerar(int a) {
		if(this.ligado == true) {
			this.vezesAcelerou++;
			System.out.println("Acelerando o " + modelo + " para " + a);
		}
		else System.out.println("Carro desligado");
	}
	
	public void frear() {
		if(this.ligado == true) {
			this.vezesFreou++;
			System.out.println("Freando o " + modelo);
		}
		else System.out.println("O carro não está em movimento");
	}
	
	public int getVezesFreou() {
		return this.vezesFreou;
	}
	
	public int getVezesAcelerou() {
		return this.vezesAcelerou;
	}
	
	public int getVezesLigou() {
		return this.vezesLigou;
	}
	
	public static void main(String args[]) {
		Carro c1 = new Carro("Volkswagen", "Gol", "ABC-1234");
		
		c1.acelerar(60);
		c1.ligar();
		c1.acelerar(60);
		c1.acelerar(100);
		c1.frear();
		c1.desligar();
		c1.ligar();
		c1.acelerar(50);
		c1.frear();
		System.out.println("Vezes que acelerou: " + c1.getVezesAcelerou());
		System.out.println("Vezes que freou: " + c1.getVezesFreou());
		System.out.println("Vezes que ligou: " + c1.getVezesLigou());
	}	
}

