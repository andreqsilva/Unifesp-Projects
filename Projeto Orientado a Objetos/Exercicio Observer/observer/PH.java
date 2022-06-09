package observer;

public class PH extends Observable{
	private double myData;
	
	public PH() {}
		
	public void setData(double data) {
		myData = data;
		System.out.println("PH foi atualizado");
		notifyObserver();
	}
	
	public double getData() {
		return myData;
	}
}
