package lista;
import java.util.Scanner;

public class Media {
	static double calculaMedia(double A[], int n) {
		int i;
		double soma = 0;
		for(i = 0; i < n; i++) {
			soma += A[i]; 
		}
		return soma/n;
	}
	
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in); 
		double A[] = new double[5];
		int i;
		
		for(i = 0; i < A.length; i++) {
			A[i] = scan.nextInt();
		}
		
		System.out.println(calculaMedia(A, A.length));
		
	}
}
