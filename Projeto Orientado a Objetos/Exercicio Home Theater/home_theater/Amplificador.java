package home_theater;

public class Amplificador {
	private int volume;
	public Amplificador() {
		this.volume = 30;
	}
	
	public int getVolume() {
		return volume;
	}
	
	public void aumentarVolume() {
		if(volume < 100) {
			volume += 5;
		}
	}
	
	public void diminuirVolume() {
		if(volume > 0) {
			volume -= 5;
		}
	}
}
