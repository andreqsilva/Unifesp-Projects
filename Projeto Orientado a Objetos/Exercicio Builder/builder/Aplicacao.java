package builder;

public class Aplicacao {
	public static void main(String[] args) {
		//criando uma pessoa aleatória//
		PessoaBuilder pessoaBuilder = new PessoaBuilder().criarPessoa("Ana", "1234-5");	
		Pessoa pessoa = pessoaBuilder.get();
		System.out.println(pessoa.toString());
		
		//criando uma empresa//
		EmpresaBuilder empresaBuilder = new EmpresaBuilder().criarEmpresa("Carlos", "5555-5");
		Empresa empresa = empresaBuilder.get();
		System.out.println("\n" + empresa.toString());
		
		//verificando se a pessoa responsável foi criada//
		System.out.println("\n" + empresa.getPessoaResponsavel().toString());
	}
}
