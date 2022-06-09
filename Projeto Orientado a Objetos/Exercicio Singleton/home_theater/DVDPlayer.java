package home_theater;

public class DVDPlayer {
	private String nomeDVD;
	private boolean temDVD;
	public DVDPlayer() {
		this.temDVD = false;
	}
	
	public boolean getTemDVD() {
		return temDVD;
	}
	
	public String getNomeDVD() {
		return nomeDVD;
	}	
	
	public void colocarDVD(String nome) {
		if(getTemDVD()) {
			System.out.println("Já tem um DVD inserido");
		}
		else {
			nomeDVD = nome;
			temDVD = true;
		}
	}
	
	public void tirarDVD(String nome) {
		if(!getTemDVD()) {
			System.out.println("Nenhum DVD foi inserido");
		}
		else {
			nomeDVD = null;
			temDVD = false;
		}
	}
	
	public void playDVD() {
		if(!getTemDVD()) {
			System.out.println("Insira um DVD");
		}
		else {
			System.out.println("Play DVD...");
		}
	}
}
