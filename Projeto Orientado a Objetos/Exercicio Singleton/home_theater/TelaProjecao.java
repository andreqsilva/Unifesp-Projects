package home_theater;

public class TelaProjecao {
	public boolean ligadoDesligado = false;
	public boolean temDVD;
	public DVDPlayer dvdPlayer;
	public TelaProjecao() {
		this.temDVD = false;
	}
	
	public void LigarDesligarTela() {
		if(ligadoDesligado) {
			ligadoDesligado = false;
			System.out.println("Desligando tela...");
		}
		else {
			ligadoDesligado = false;
			System.out.println("Ligando tela...");
		}
	}
	
	public void conectarDVD(DVDPlayer dvd) {
		if(temDVD) {
			System.out.println("DVD já conectado");
		}
		else {
			dvdPlayer = dvd;
		}
	}
	
	public void assistirDVD() {
		if(dvdPlayer.getTemDVD()) {
			System.out.println("Exibindo " + dvdPlayer.getNomeDVD() + "...");
		} 
	}
}
