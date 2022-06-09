package heranca_2;

class Nodo {
	private int info;
	private Nodo prox;
	
	public int getInfo() {
		return this.info;
	}
	
	public Nodo getProx() {
		return this.prox;
	}
	
	public void setInfo(int _info) {
		this.info = _info;
	}
	
	public void setProx(Nodo _prox) {
		this.prox = _prox;
	}
	
}

public class Lista {
	private Nodo primeiro;
	public Lista() {
		primeiro = null;
	}
	
	public Nodo getPrimeiro() {
		return this.primeiro;
	}
	
	protected void setPrimeiro(Nodo _primeiro) {
		this.primeiro = _primeiro;
	}
	
	public void insere(int c) {
		Nodo novo = new Nodo();
		novo.setInfo(c);
		novo.setProx(primeiro);
		primeiro = novo;
	}
	
	public void imprime() {
		for(Nodo i = primeiro; i != null; i = i.getProx()) {
			System.out.print(i.getInfo() + " ");
		}
		System.out.print("\n");
	}
	
	public static void main(String[] args) {
		Fila fila = new Fila();
		Pilha pilha = new Pilha();
		
		System.out.println("Fila --> First-In-First-Out");
		fila.insere(1);
		fila.insere(2);
		fila.insere(4);
		fila.imprime();
		fila.remove();
		fila.imprime();
		
		System.out.println("Pilha --> Last-In-First-Out");
		pilha.insere(1);
		pilha.insere(2);
		pilha.insere(4);
		pilha.imprime();
		pilha.remove();
		pilha.imprime();
	}
}

class Pilha extends Lista {
	private Nodo ant;
	public Pilha() {
		super();
		ant = null;
	}
	
	public Nodo getAnt() {
		return this.ant;
	}
	public void setAnt(Nodo _ant) {
		this.ant = _ant;
	}
	
	public void insere(int c) { //COLOCAR ANT
		Nodo novo = new Nodo();
		novo.setInfo(c);
		novo.setProx(getPrimeiro());
		setPrimeiro(novo);
	}
	
	public void remove() {
		if(getPrimeiro() == null) System.err.println("Fila vazia");
		else 
			setPrimeiro(getPrimeiro().getProx());
	}
}

class Fila extends Lista {
	private Nodo ultimo;
	public Fila() {
		super();
		ultimo = null;
	}
	
	public Nodo getUltimo() {
		return this.ultimo;
	}
	private void setUltimo(Nodo _ultimo) {
		this.ultimo = _ultimo;
	}
	
	public void insere(int c) {
		Nodo novo = new Nodo();
		novo.setInfo(c);
		if(getPrimeiro() == null) {
			setPrimeiro(novo);
			setUltimo(getPrimeiro());
		}
		else {
			getUltimo().setProx(novo);
			setUltimo(novo);
		}
	}
	
	public void remove() {
		if(getPrimeiro() == null) System.err.println("Fila vazia");
		else {
			if(getPrimeiro() == ultimo) {
				setPrimeiro(null);
				setUltimo(null);
			}
			else setPrimeiro(getPrimeiro().getProx());
		}
	}
}