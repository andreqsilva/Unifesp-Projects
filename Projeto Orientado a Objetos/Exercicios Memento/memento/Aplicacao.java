package memento;

public class Aplicacao {
	public static void main(String[] args) {
		Zelador zelador = new Zelador();
		Fonte fonte = new Fonte();
		Estado estadoA = new EstadoA();
		Estado estadoB = new EstadoB();
		
		fonte.setEstado(estadoA);
		fonte.setEstado(estadoB);
		zelador.addMemento(fonte.criarMemento());
		
		fonte.setEstado(estadoA);
		zelador.addMemento(fonte.criarMemento());
		
		// utilizando o setMemento //
		fonte.setMemento(zelador.getMemento(0));
		zelador.addMemento(fonte.criarMemento());
		
		System.out.println("\nArray zelador");
		System.out.println(zelador.getMemento(0).getEstado().toString());
		System.out.println(zelador.getMemento(1).getEstado().toString());
		System.out.println(zelador.getMemento(2).getEstado().toString());
		
	}
}
