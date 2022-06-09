package responsibility;

public interface Caractere {
	public void setSucessor(Caractere caractere);
	public int getQuantidade();
	public void incrementa();
	public boolean isCaractere(char caractere);
}
