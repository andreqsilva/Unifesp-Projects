package home_theater;

public class Aplicacao {
	public static void main(String[] args) {
		HomeTheater controle1, controle2, controle3;
		controle1 = HomeTheater.obterInstancia();
		controle2 = HomeTheater.obterInstancia();
		
		if(controle1 == controle2) {
			System.out.println("controle1 e controle2 são o mesmo objeto");
		}
		
		controle1.ligarDesligarLuz();
		controle1.ouvirMusica("Jazz");
		controle2.ouvirMusica("Rock");
		controle1.diminuirVolume();
		controle2.diminuirVolume();
		controle1.prepararMaquinas(500, "Fanta");
		controle2.ligarDesligarLuz();
		controle1.assistirFilme("Vingadores");
	}
}
