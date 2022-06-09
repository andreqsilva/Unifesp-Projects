package memento;

public class Fonte {
	private Object estado;
	
	public void setEstado(Object estado) {
		System.out.println("Set estado: " + estado.toString());
		this.estado = estado;
	}
	
	public Memento criarMemento() {
		System.out.println("Criando Memento com o " + estado.toString());
		return new Memento(estado);
	}
	
	public void setMemento(Memento m) {
		System.out.println("Set memento: " + m.getEstado());
		estado = m.getEstado();
	}
}
