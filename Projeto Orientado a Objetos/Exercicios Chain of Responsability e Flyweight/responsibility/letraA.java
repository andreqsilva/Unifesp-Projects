package responsibility;

public class letraA implements Caractere {
	private Caractere sucessor;
	private int nroA = 0;
	 
	@Override
	public int getQuantidade() {
		return nroA;
	}
	
	@Override
	public void incrementa() {
		nroA += 1;
	}
	 
	@Override
	public boolean isCaractere(char caractere) {
		if(caractere == 'a' || caractere == 'A') {
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
