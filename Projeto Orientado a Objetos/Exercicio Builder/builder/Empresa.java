package builder;

public class Empresa {
	private Pessoa pessoaResponsavel;
	private String nomeResponsavel;
	private String identidadeResponsavel;
	
	public void setPessoa(Pessoa pessoa) {
		this.pessoaResponsavel = pessoa;
	}
	
	public void setNomeResponsavel(String nome) {
		this.nomeResponsavel = nome;
	}
	
	public void setIdentidadePessoaResponsavel(String identidade) {
		this.identidadeResponsavel = identidade;
	}
	
	public Pessoa getPessoaResponsavel() {
		return this.pessoaResponsavel;
	}
	
	public String getNomePessoaResponsavel() {
		return this.nomeResponsavel;
	}
	
	public String getIdentidadePessoaResponsavel() {
		return this.identidadeResponsavel;
	}
	
	
	public String toString() {
		return "Nome da pessoa responsável: " 
				+ this.pessoaResponsavel.getNome() + "\nIdentidade da pessoa responsável: "
				+ this.pessoaResponsavel.getIdentidade() + "\nEMPRESA CRIADA";
	}
}
