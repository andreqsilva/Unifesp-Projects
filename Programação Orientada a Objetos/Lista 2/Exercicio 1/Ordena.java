package lista;
import java.util.Scanner;

public class Ordena {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		int n = 0, a, i, j, aux;
		int A[] = new int[100];
		
		a = scan.nextInt();
		while(a != 0) {
			A[n] = a;
			n++;
			a = scan.nextInt();
		}
		
		for(i = 0; i < n; i++) {
			for(j = i+1; j < n; j++) {
				if(A[i] > A[j]) {
					aux = A[i];
					A[i] = A[j];
					A[j] = aux;
				}
			}
		}
		
		for(i = 0; i < n; i++) {
			System.out.print(A[i] + " ");
		}
	}
}
