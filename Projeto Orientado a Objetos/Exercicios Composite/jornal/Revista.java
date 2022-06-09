package jornal;
import java.util.ArrayList;
import java.util.List;

import composite_congresso.Instituicao;

public class Revista implements Publicacao{
	private String nome;
	private int total;
	protected List<Artigo> publicacoes = new ArrayList<Artigo>();
	public Revista(String nome) {
		this.nome = nome;
		this.total = 0;
	}
	
	public void addPublicacao(Artigo publicacao) {
		publicacoes.add(publicacao);
		total++;
	}
	
	public List<Artigo> getPublicacoes() {
		return publicacoes;
	}
	
	public int totalPublicacoes() {
		return total;
	}
		
	@Override
	public String toString() {
		return nome;		
	}
	
}
