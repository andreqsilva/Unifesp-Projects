package lista_heranca;

public abstract class Mortal {
	private boolean vivo;
	public Mortal() {
		this.vivo = true;
	}
	
	public boolean isVivo() {
		return this.vivo;
	}
	
	public void mata() {
		this.vivo = false;
	}
	
	public abstract String toString();
	
	//exercicio 5
	public static void main(String args[]) {
		Gato geraldo = new Gato();
		Ramo ramo = new Ramo();
		
		System.out.println(geraldo.toString());
		for(int i = 0; i < 7; i++) {
			geraldo.mata();
			if(geraldo.isVivo() == true)
				System.out.println("Vivo");
			else
				System.out.println("Morto");
		}
		
		ramo.insere(5);
		ramo.insere(3);
		ramo.insere(2);
		
		System.out.println(ramo.toString());
		System.out.println(ramo.isVivo());
		ramo.mata();
		System.out.println(ramo.isVivo());
	}
}