package observer;

public class PressaoAtmosferica extends Observable{
	private double myData;
	
	public PressaoAtmosferica() {}
	
	public void setData(double data) {
		myData = data;
		System.out.println("Pressão atmosférica foi atualizada");
		notifyObserver();
	}
	
	public double getData() {
		return myData;
	}
}
