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
		System.out.println("Conta " + this.numero + " " + "Saldo " + this.saldo);
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
	public void imprime() {
		System.out.println("Conta " + this.getNumero() + " " + "Saldo " + this.getSaldo() + " " + "Juros " + this.juros);
	}
}

class ContaCorrente extends Conta {
	public ContaCorrente(int _numero) {
		super(_numero);
	}
	private double limite = 1000;
	public double getLimite() {return this.limite;}
	public void imprime() {
		System.out.println("Conta " + this.getNumero() + " " + "Saldo " + this.getSaldo() + " " + "Limite " + this.limite);
	}
}

