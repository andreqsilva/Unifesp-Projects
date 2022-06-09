package lista;

class NoDeArvore {
	int item;
	NoDeArvore esquerda;
	NoDeArvore direita;
	public NoDeArvore(int _item) {
		item = _item;
	}
}

public class ArvoreBinaria {	
	static void inserir(NoDeArvore node, int valor) {
		if(valor < node.item) {
			if(node.esquerda != null) {
				inserir(node.esquerda,valor);
			}
			else {
				node.esquerda = new NoDeArvore(valor);
			}
		}
		else if(valor > node.item) {
			if(node.direita != null) {
				inserir(node.direita,valor);
			}
			else {
				node.direita = new NoDeArvore(valor);
			}
		}
	}
	
	static void procura(NoDeArvore node, int valor) {
		if(node != null) {
			if(node.item == valor) {
				System.out.println("\n"+ valor + " pertence a arvore");
			}
			procura(node.esquerda,valor);
			procura(node.direita,valor);
		}
		
	}
	
	static void imprime(NoDeArvore node) {
		if(node != null) {
			System.out.print(node.item + " ");
			imprime(node.esquerda);
			imprime(node.direita);
		}
	}
	
	public static void main(String args[]) {
		NoDeArvore raiz = new NoDeArvore(5);
		inserir(raiz,3);
		inserir(raiz,2);
		inserir(raiz,4);
		inserir(raiz,1);
		inserir(raiz,7);
		inserir(raiz,6);
		imprime(raiz);
		procura(raiz,3);
		
	}
}
