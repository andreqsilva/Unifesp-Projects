package home_theater;

public class Aplicacao {
	public static void main(String[] args) {
		HomeTheater controle = new HomeTheater();
		controle.ligarDesligarLuz();
		controle.ouvirMusica("Jazz");
		controle.diminuirVolume();
		controle.diminuirVolume();
		controle.prepararMaquinas(500, "Fanta");
		controle.ligarDesligarLuz();
		controle.assistirFilme("Vingadores");
	}
}
