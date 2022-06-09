package excecoes;

public class TesteExcecao {
	public static void metodo(String message) throws NovaExcecao {
		if(message == null) throw new NovaExcecao("Mensagem nula");
	}
	public static void main(String args[]) {
		String message = null;
		try {
			metodo(message);
		}
		catch(NovaExcecao ex) {
			System.out.println(ex.getMensagem());
			message = "Mensagem vazia";
		}
		System.out.println(message);
	}
}
