package strings;
import java.util.*;

public class PigLatin {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		char[] letras = null;	
		String palavra;
		
		String usuario = scan.nextLine();
		StringTokenizer frase  = new StringTokenizer(usuario);
		
		while(frase.hasMoreTokens()) {
			palavra = frase.nextToken();
			letras = palavra.toCharArray();
			System.out.println(palavra.substring(1)  + letras[0] + "ay");
		}
	}
}
