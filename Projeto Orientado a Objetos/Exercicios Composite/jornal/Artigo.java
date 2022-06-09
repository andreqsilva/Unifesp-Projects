package jornal;
import java.util.List;

public class Artigo implements Publicacao{
	private String nome;
	private String[] autores = new String[5];
	public Artigo(String nome, String autores[]) {
		this.nome = nome;
		this.autores = autores;
	} 
	
	protected String getNome() {
		return nome;
	}
	
	protected String[] getAutores() {
		return autores;
	}
	
	public String toString() {
		return getNome() + "\n" + getAutores();
	}
}
