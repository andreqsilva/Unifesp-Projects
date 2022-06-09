package builder;

public class PessoaBuilder extends Construtor{
	private Pessoa pessoa;
	
	public PessoaBuilder() {
		this.pessoa = new Pessoa();
	}
	
	@Override	
	public PessoaBuilder criarPessoa(String nome, String identidade) {
		pessoa.setNome(nome);
		pessoa.setIdentidade(identidade);
		return this;
	}
 	
	public Pessoa get() {
		return pessoa;
	}

}
