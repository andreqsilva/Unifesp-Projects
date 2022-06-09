package observer;
import java.util.ArrayList;
import java.util.Iterator;

public class Observable {
	private ArrayList<Observer> observers = new ArrayList();
	
	public void add(Observer o) {
		observers.add(o);
	}
	
	public void remove(Observer o) {
		observers.remove(o);
	}
	
	public void notifyObserver() {
		Iterator it = observers.iterator();
		while(it.hasNext()) {
			Observer o = (Observer)it.next();
			if(o instanceof InstitutoA) {
				System.out.println("Instituto A foi notificado");
			}
			if(o instanceof InstitutoB) {
				System.out.println("Instituto B foi notificado");
			}
			o.update(this);
		}
	}
}
