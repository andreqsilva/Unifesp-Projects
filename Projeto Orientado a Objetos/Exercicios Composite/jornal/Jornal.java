package jornal;

import java.util.ArrayList;
import java.util.List;

public class Jornal {
	private String nome;
	private int total;
	protected List<Publicacao> publicacoes = new ArrayList<Publicacao>();
	public Jornal(String nome) {
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
	
	public String toString() {
		return nome;		
	}
	
	public static void main(String[] args) {
		String[] autores1 = new String[5];
		String[] autores2 = new String[5];
		String[] autores3 = new String[5];
		
		autores1[0] = "Albert Einstein";
		autores1[1] = "Carl Sagan";
		autores2[0] = "Átila";
		autores3[0] = "Galileu Galilei";
		autores3[1] = "Nicolau Copérnico";
				
		Artigo artigo1 = new Artigo("Física", autores1);
		Artigo artigo2 = new Artigo("Covid", autores2);
		Artigo artigo3 = new Artigo("Virologia", autores2);
		Artigo artigo4 = new Artigo("Astronomia", autores3);
		
		Revista revista1 = new Revista("Science");
		Revista revista2 = new Revista("Superinteressante");
		revista1.addPublicacao(artigo1);
		revista1.addPublicacao(artigo2);
		revista2.addPublicacao(artigo3);
		
		System.out.println("Revista " + revista1.toString());
		System.out.println("Artigos publicados:");
		for(Artigo publicacoes : revista1.getPublicacoes()) {
			System.out.println(publicacoes.toString());
		}
		System.out.println("Número de publicações da revista " + revista1.toString() + ": " + revista1.totalPublicacoes());
		
		System.out.println("\nRevista " + revista2.toString());
		System.out.println("Artigos publicados:");
		for(Artigo publicacoes : revista2.getPublicacoes()) { 
			System.out.println(publicacoes.toString());
		}
		System.out.println("Número de publicações da revista " + revista2.toString() + ": " + revista2.totalPublicacoes());
		
		Caderno caderno1 = new Caderno("Ciência");
		caderno1.addPublicacao(revista1);
		caderno1.addPublicacao(artigo4);
		System.out.println("\nCaderno sobre " + caderno1.toString());
		System.out.println("Publicações contidas:");
		for(Publicacao publicacoes : caderno1.getPublicacoes()) {
			if(publicacoes instanceof Artigo) {
				System.out.println("Artigo " + publicacoes.toString());
			}
			else {
				System.out.println("Revista " + publicacoes.toString());
			}
			
		}
		
		Jornal jornal = new Jornal("Dia");
		jornal.addPublicacao(caderno1);
		jornal.addPublicacao(revista1);
		jornal.addPublicacao(artigo2);
		
		System.out.println("\nJornal " + jornal.toString());
		System.out.println("Publicações contidas: ");
		for(Publicacao publicacoes : jornal.getPublicacoes()) {
			if(publicacoes instanceof Artigo) {
				System.out.println("Artigo " + publicacoes.toString());
			}
			else if (publicacoes instanceof Revista){
				System.out.println("Revista " + publicacoes.toString());
			}
			else  {
				System.out.println("Caderno " + publicacoes.toString());
			}
		}
	}
}
