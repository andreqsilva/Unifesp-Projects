package lista_heranca;

public class Gato extends Mortal {
	private int vidas;
	public Gato() {
		super();
		this.vidas = 7;
	}
	
	public int getVidas() {
		return this.vidas;
	}
	
	@Override
	public void mata() {
		if(this.getVidas() > 1) {
			this.vidas--;
		}
		else super.mata();
	}
	
	//tosString exercicio 4
	@Override
	public String toString() {
		return "Gato";
	}
}
