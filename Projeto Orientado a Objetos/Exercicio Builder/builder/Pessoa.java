package builder;

public class Pessoa {
	private String nome;
	private String identidade;
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public void setIdentidade(String identidade) {
		this.identidade = identidade;
	}
	
	public String getNome() {
		return nome;
	}
	
	public String getIdentidade() {
		return identidade;
	}
	
	public String toString() {
		return "Nome: " + getNome() + "\nIdentidade: " + getIdentidade() + "\nPESSOA CRIADA"; 
	}
}
