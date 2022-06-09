package lista;
import java.util.Random;

public class VetorAleatorio {
	private static int tamanho;
	public VetorAleatorio(int _tamanho) {
		tamanho = _tamanho;
	}
	static void geraVetor(double A[]) {
		int i;
		Random gerador = new Random(); 
		for(i = 0; i < tamanho; i++) {
			A[i] = gerador.nextDouble();
		}
	}
	
	public static void main(String args[]) {
		double A[] = new double[10];
		VetorAleatorio novoVetor = new VetorAleatorio(10);
		geraVetor(A);
		
		for(int i = 0; i < 10; i++) {
			System.out.print(A[i] + " ");
		}
	}
}
