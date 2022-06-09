package composite_congresso;
import java.util.ArrayList;
import java.util.List;

public class Instituicao extends Congressista{
	private int total = 0;
	protected List<Individuo> componentes = new ArrayList<Individuo>();
	public Instituicao(Individuo individuo) {
		add(individuo);
	}
	
	public void add(Individuo individuo) {
		componentes.add(individuo);
		total++;
	}
	
	public void remove(Individuo individuo) {
		componentes.remove(individuo);
		total--;
	}
	
	public List<Individuo> getMembros() {
		return componentes;
	}

	public int totalParticipantes() {
		return total;
	} 
}
