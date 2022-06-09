package jornal;
import java.util.ArrayList;
import java.util.List;

public class Caderno implements Publicacao{
	private String nome;
	private int total;
	protected List<Publicacao> publicacoes = new ArrayList<Publicacao>();
	public Caderno(String nome) {
		this.nome = nome;
		this.total = 0;
	}
	
	public void addPublicacao(Publicacao publicacao) {
		publicacoes.add(publicacao);
		total++;
	}
	
	public List<Publicacao> getPublicacoes() {
		return publicacoes;
	}
	
	@Override
	public String toString() {
		return nome;		
	}
	
}
