package queue;

public class QueueList extends QueueAbstract{
	protected ListInterface list;
	public QueueList(ListInterface list) {
		this.list = list;
	}
	
	public void dequeue() {
		list.remove(0);
	}
	
	public void enqueue(int index) {
		list.add(index);
	}
	
	public boolean isEmpty() {
		return list.isEmpty();
	}
	
	public int size() {
		return list.size();
	}
	
	public String toString() {
		return list.toString();
	}	
}
