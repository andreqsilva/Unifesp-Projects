package queue;

public class Cliente {
	public static void main(String[] args) {
		QueueList filaArrayList = new QueueList(new ImplArrayList());
		filaArrayList.enqueue(1);
		filaArrayList.enqueue(2);
		filaArrayList.dequeue();
		System.out.println(filaArrayList.toString());
		
		QueueList filaVector = new QueueList(new ImplVectorQueue());
		filaVector.enqueue(1);
		filaVector.enqueue(2);
		filaVector.enqueue(3);
		filaVector.enqueue(4);
		filaVector.dequeue();
		filaVector.dequeue();
		System.out.println(filaVector.toString());
	}
}
