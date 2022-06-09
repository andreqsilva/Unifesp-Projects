package queue;
import java.util.ArrayList;
import java.util.List;

public class ImplArrayList implements ListInterface{
	private List fila = new ArrayList<>();
	
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
