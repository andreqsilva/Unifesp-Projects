package queue;
import java.util.LinkedList;
import java.util.Queue;

public class QueueAbstract {
	private Queue <Integer> fila = new LinkedList<>();
	
	public void dequeue() {
		fila.remove();
	}
	
	public void enqueue(int index) {
		fila.add(index);
	}
	
	public boolean isEmpty() {
		return fila.isEmpty();
	}
	
	public int size() {
		return fila.size();
	}
	
	public String toString() {
		return fila.toString();
	}	
}
