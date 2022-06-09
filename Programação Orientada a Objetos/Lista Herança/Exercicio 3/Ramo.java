package lista_heranca;

class Nodo {
	private int info;
	private Nodo dir;
	private Nodo esq;
	
	public int getInfo() {
		return this.info;
	}
	
	public Nodo getDIr() {
		return this.dir;
	}
	
	public Nodo getEsq() {
		return this.esq;
	}
	
	public void setInfo(int _info) {
		this.info = _info;
	}
	
	public void setDir(Nodo _dir) {
		this.dir = _dir;
	}
	
	public void setEsq(Nodo _esq) {
		this.esq = _esq;
	}
}

public class Ramo extends Mortal{
	private Nodo raiz;
	public Ramo() {
		super();
		raiz = null;
	}
	
	public void insere(int c) {
		Nodo novo = new Nodo();
		novo.setInfo(c);
		novo.setDir(null);
		novo.setEsq(null);
		
		if(raiz == null ) raiz = novo;
		else if(raiz.getDIr() == null) raiz.setDir(novo);
		else raiz.setEsq(novo);
	}
	
	public void mata() {
		this.raiz = null;
		super.mata();
	}
	
	@Override
	public String toString() {
		return "Ramo";
	}
	/*
	public static void main(String args[]) {
		Ramo ramo = new Ramo();

		ramo.insere(5);
		ramo.insere(3);
		ramo.insere(2);
	
		System.out.println(ramo.raiz.getInfo() + " " + ramo.raiz.getDIr().getInfo() + " " + ramo.raiz.getEsq().getInfo());
	}
	*/
}
