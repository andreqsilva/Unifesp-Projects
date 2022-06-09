package exercicios_heranca;

public abstract class Conta {
	private double saldo;
	private int numero;
	public Conta(int a) {
		this.saldo = 0.0;
		this.numero = a;
	}
	
	public void debita(double quantia) {
		this.saldo -= quantia;
	}
	public void credita(double quantia) {
		if (quantia > 0) saldo += quantia;
		else 
			System.err.println("Conta.saca(...): " + "não se pode sacar uma quantia negativa.");
	}
	public double getSaldo() {return this.saldo;}
	public double getNumero() {return this.numero;}
	public void imprime() {
		System.out.println("Conta " + this.numero + "\n" + "Saldo " + this.saldo);
	}
	
	public static void main(String[] args) {
		ContaCorrente c1 = new ContaCorrente(1234);
		ContaPoupanca c2 = new ContaPoupanca(1111);
		
		c1.credita(1000);
		c1.debita(300);
		
		c2.credita(2000);
		c2.debita(500);
		c2.adcionaJuros(0.5);
	
		c1.imprime();
		System.out.println("Limite " + c1.getLimite());
		c2.imprime();
		System.out.println("Juros " + c2.getJuros());		
	}
}

class ContaPoupanca extends Conta {
	public ContaPoupanca(int _numero) {
		super(_numero);
	}
	private double juros;
	public double getJuros() {return this.juros;}
	public void adcionaJuros(double _juros) {
		this.juros = _juros;
	}
}

class ContaCorrente extends Conta {
	public ContaCorrente(int _numero) {
		super(_numero);
	}
	private double limite = 1000;
	public double getLimite() {return this.limite;}
}

