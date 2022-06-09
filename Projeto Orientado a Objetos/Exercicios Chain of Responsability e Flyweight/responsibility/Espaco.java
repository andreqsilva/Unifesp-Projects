package responsibility;

public class Espaco implements Caractere {
	private Caractere sucessor;
	private int nroEspaco = 0;
	
	@Override
	public int getQuantidade() {
		return nroEspaco;
	}
	 
	@Override
	public void incrementa() {
		nroEspaco += 1;
	}
	 
	@Override
	public boolean isCaractere(char caractere) {
		if(caractere == ' ') {
			this.incrementa();
			return true;
		}
		else {
			return sucessor.isCaractere(caractere);
		}
	}
	 
	@Override
	public void setSucessor(Caractere proximo) {
		this.sucessor = proximo;
	}
}
