package observer;

public class Temperatura extends Observable{
	private double myData;
	
	public Temperatura() {}
	
	public void setData(double data) {
		myData = data;
		System.out.println("Temoperatura foi atualizada");
		notifyObserver();
	}
	
	public double getData() {
		return myData;
	}
}
