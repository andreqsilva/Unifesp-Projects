package aula3;

public class Contador {
	private int contagem;
	private int valor;
	public Contador() {
		this.contagem = 0;
		this.valor = 0;
	}
	public Contador(int i) {
		this.contagem = i;
		this.valor = i;
	}
	
	public void incrementa_unidade() {
		this.contagem += 1;
		this.valor = 1;
	}
	
	public void incrementa_valor(int v) {
		this.contagem += v;
		this.valor = v;
	}
	
	public void decrementa_unidade() {
		if(this.contagem > 0) {
			this.contagem -= 1;
		}
	}
	
	public void decrementa_valor(int v) {
		if(v > this.contagem) {
			this.contagem = 0;
		}
		else this.contagem -= v;
	}
	
	public int getContagem() {
		return this.contagem;
	}
	
	public int getValor() {
		return this.valor;
	}
	
	public static void main(String args[]) {
		Contador c1 = new Contador(2);
		
		System.out.println(c1.getContagem());
		c1.incrementa_unidade();
		c1.incrementa_unidade();
		c1.incrementa_valor(12);
		c1.decrementa_unidade();
		c1.decrementa_valor(5);
		System.out.println(c1.getValor());
		System.out.println(c1.getContagem());
	}
}
