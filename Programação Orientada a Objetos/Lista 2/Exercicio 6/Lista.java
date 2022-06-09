package lista;

class No {
	private int info;
	private No prox;
	
	public int getInfo() {
		return this.info;
	}
	
	public No getProx() {
		return this.prox;
	}
	
	public void setInfo(int _info) {
		this.info = _info;
	}
	
	public void setProx(No _prox) {
		this.prox = _prox;
	}
	
}

public class Lista {
	private No primeiro;
	public Lista() {
		primeiro = null;
	}
	
	public No getPrimeiro() {
		return this.primeiro;
	}
	
	protected void setPrimeiro(No _primeiro) {
		this.primeiro = _primeiro;
	}
	
	public void insere(int c) {
		No novo = new No();
		novo.setInfo(c);
		novo.setProx(primeiro);
		primeiro = novo;
	}
	
	public void imprime() {
		for(No i = primeiro; i != null; i = i.getProx()) {
			System.out.print(i.getInfo() + " ");
		}
		System.out.print("\n");
	}
	
	private int buscaNo(int c) {
		for(No i = primeiro; i != null; i = i.getProx()) {
			if(i.getInfo() == c) return 1;
		}
		return 0;
	}
	
	public void remove(int c) {
		if(buscaNo(c) == 1) {
			No elimina = primeiro;
			if(primeiro.getInfo() == c) {
				primeiro = elimina.getProx();
			}
			else {
				while(elimina != null) {
					No ant = elimina;
					elimina = elimina.getProx();
					if(elimina.getInfo() == c) {
						ant.setProx(elimina.getProx());
						break;
					}
				}
			}
		}
		else System.out.println("Nó não encontrado");
	}
	
	public int somaInteiros() {
		int soma = 0;
		for(No i = primeiro; i != null; i = i.getProx()) {
			soma += i.getInfo();
		}
		return soma;
	}

	public static void main(String[] args) {
		Lista lista = new Lista();
		int i;
		
		for(i = 1; i <= 5; i++)
			lista.insere(i);
		
		System.out.println(lista.somaInteiros());
		
		lista.imprime();
		lista.remove(3);
		lista.imprime();
		
	}
}
