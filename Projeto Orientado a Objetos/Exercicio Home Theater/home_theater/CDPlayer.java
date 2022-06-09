package home_theater;

public class CDPlayer {
	private String nomeCD;
	private Amplificador amplificador;
	private boolean temAmplificador;
	private boolean temCD;
	public CDPlayer() {
		this.temCD = false;
		this.temAmplificador = false;
	}
	
	public String getnomeCD() {
		return nomeCD;
	}
	
	public boolean getTemCD() {
		return temCD;
	}
	
	public void conectarAplificador(Amplificador amplificador) {
		amplificador = amplificador;
		temAmplificador = true;
	}

	public void colocarCD(String nome) {
		if(getTemCD()) {
			System.out.println("Já tem um CD inserido");
		}
		else {
			nomeCD = nome;
			temCD = true;
		}
	}
	
	public void tirarCD() {
		if(!getTemCD()) {
			System.out.println("Nenhum CD foi inserido");
		}
		else {
			nomeCD = null;
			temCD = false;
		}
	}
	
	public void playCD() {
		if(!getTemCD()) {
			System.out.println("Insira um CD");
		}
		else {
			System.out.println("Tocando " + nomeCD + "...");
		}
	}
}
