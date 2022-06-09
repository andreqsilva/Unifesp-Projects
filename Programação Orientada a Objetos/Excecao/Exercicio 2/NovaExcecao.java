package excecoes;
import java.lang.Exception;

public class NovaExcecao extends Exception {
	private String mensagem;
	public NovaExcecao() {}
	public NovaExcecao(String _message) {
		mensagem = _message;
	}
	public String getMensagem() {
		return this.mensagem;
	}	
}



