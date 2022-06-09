package home_theater;

public class MaquinaPipoca {
	private double quantiaPipoca;
	public MaquinaPipoca() {
		this.quantiaPipoca = 0;
	}
	
	public void colocarPipoca(double quantia) {
		quantiaPipoca = quantia;
	}
	
	public double getQuantiaPipoca() {
		return quantiaPipoca;
	}
	
	public void estourarPipoca() {
		System.out.println("Estourando " + getQuantiaPipoca() + " mg de pipoca...");
	}
}
