package lista;
import java.util.Scanner;

public class MaiorInteiro {
	static int encontraMaior(int A[]) {
		int i, maior;
		maior = A[0];
		for(i = 1; i < A.length; i++) {
			if(A[i] > maior) maior = A[i];
		}
		return maior;
	}
	
	public static void main(String args[]) {
		int A[] = new int[5];
		int i;
		Scanner scan = new Scanner(System.in);
		
		for(i = 0; i < A.length; i++) {
			A[i] = scan.nextInt();
		}
		
		System.out.println(encontraMaior(A));
	}
}
