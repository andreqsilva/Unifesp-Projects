package queue;
import java.util.Vector;

public class ImplVectorQueue implements ListInterface{
	private Vector fila = new Vector();
	
	@Override
	public void add(int index) {
		fila.add(index);
	}

	@Override
	public void remove(int index) {
		fila.remove(index);
	}
	
	@Override
	public boolean isEmpty() {
		return fila.isEmpty();
	}
	
	@Override
	public int size() {
		return fila.size();
	}
	
	@Override
	public String toString() {
		return fila.toString();
	}
}
