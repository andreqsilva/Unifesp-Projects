package composite_congresso;

public class Individuo extends Congressista{
	private int assento;
	public Individuo(int assento) {
		this.assento = assento;
	}
	
	@Override
	public int getAssento() {
		return assento;
	}
}
