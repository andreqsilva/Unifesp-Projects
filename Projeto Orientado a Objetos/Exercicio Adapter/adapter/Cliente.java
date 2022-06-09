package adapter;
import java.util.Enumeration;
import java.util.Iterator;
import java.util.ArrayList;

public class Cliente {
	public static void main(String[] args) {
		ArrayList<String> produto = new ArrayList<String>();
		
		produto.add("Carne");
		produto.add("Arroz");
		produto.add("Feijão");
		produto.add("Batata");
		produto.add("Cenoura");
		
		Iterator<String> carrinho = produto.iterator();
		
		/*
		while(carrinho.hasNext()) {	 //cliente utilizando as chamadas Iterator
			System.out.println(carrinho.next());
		}
		*/
		
		AdapterEnumeration adapterCarrinho = new AdapterEnumeration(carrinho);
		while(adapterCarrinho.hasMoreElements()) {	//cliente utilizando as chamadas Enumeration
			System.out.println(adapterCarrinho.nextElement());
		}
	}
}
