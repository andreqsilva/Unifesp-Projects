package memento;
import java.util.ArrayList;

public class Zelador {
	private ArrayList<Memento> mementos = new ArrayList<>();
	
	public void addMemento(Memento m) {
		mementos.add(m);
	}
	
	public Memento getMemento(int index) {
		return mementos.get(index);
	} 
}
