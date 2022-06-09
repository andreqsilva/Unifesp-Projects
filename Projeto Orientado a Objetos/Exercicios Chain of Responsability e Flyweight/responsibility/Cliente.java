package responsibility;
import java.util.Scanner;

public class Cliente {
	public static void encontraCaracteres(String texto) {
		final Caractere espaco = new Espaco();
		final Caractere letraA = new letraA();
		final Caractere ponto = new Ponto();
		
		espaco.setSucessor(letraA);
		letraA.setSucessor(ponto);
						
		int i;
		for(i = 0; i < texto.length(); i++) {
			espaco.isCaractere(texto.charAt(i));
		}
		
		System.out.println("Número de espaços: " + espaco.getQuantidade());
		System.out.println("Número de letras A: " + letraA.getQuantidade());
		System.out.println("Números de pontos: " + ponto.getQuantidade());
	}
	
	public static void main(String[] args) {
		Scanner read = new Scanner(System.in);
		String texto = read.nextLine();
		
		encontraCaracteres(texto);
	}
}
