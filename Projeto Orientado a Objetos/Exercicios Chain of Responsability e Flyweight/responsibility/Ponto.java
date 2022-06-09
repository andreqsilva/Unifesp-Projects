package responsibility;

public class Ponto implements Caractere {
	private Caractere sucessor;
	private int nroPonto = 0;
	
	@Override
	public int getQuantidade() {
		return nroPonto;
	}
	
	@Override
	public void incrementa() {
		nroPonto += 1;
	}
	 
	@Override
	public boolean isCaractere(char caractere) {
		if(caractere == '.') {
			this.incrementa();
			return true;
		}
		return false;
	}
	 
	@Override
	public void setSucessor(Caractere proximo) {
	}
}
