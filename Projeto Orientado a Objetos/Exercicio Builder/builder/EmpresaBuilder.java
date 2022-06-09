package builder;

public class EmpresaBuilder {
	private Pessoa pessoa;
	private Empresa empresa;
	
	public EmpresaBuilder() {
		pessoa = new Pessoa();
		empresa = new Empresa();
	}
	
	public EmpresaBuilder criarEmpresa(String nome, String identidade) {
		empresa.setNomeResponsavel(nome);
		empresa.setIdentidadePessoaResponsavel(identidade);
		return this;
	}
	
	public Empresa get() {
		PessoaBuilder pessoaBuilder = new PessoaBuilder().criarPessoa(empresa.getNomePessoaResponsavel(),
															empresa.getIdentidadePessoaResponsavel());	
		Pessoa pessoa = pessoaBuilder.get();
		empresa.setPessoa(pessoa); // cria pessoa
		return empresa;
	}


}
