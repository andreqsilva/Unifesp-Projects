package composite_congresso;
import java.util.ArrayList;
import java.util.List;

public class Congresso {
	private int total = 0;
	protected List<Congressista> membros = new ArrayList<Congressista>();
	public Congresso(Congressista congressista) {
		add(congressista);
	}
	
	public void add(Congressista congressista) {
		membros.add(congressista);
		total++;
	}
	
	public void remove(Congressista congressista) {
		membros.remove(congressista);
		total--;
	}

	public int totalAssentos() {
		return total;
	}
	
	public int totalParticipantes() {
		int totalPar = 0;
		for(Congressista c : membros) {
			if(c instanceof Individuo) {
				totalPar += 1;
			}
			else if(c instanceof Instituicao) {
				totalPar += ((Instituicao) c).totalParticipantes();
			}
		}
		return totalPar;
	}
	
	
	public static void main(String args[]) {
		//INDIVIDUOS
		Individuo individuo1 = new Individuo(1);
		Individuo individuo2 = new Individuo(2);
		Individuo individuo3 = new Individuo(3);
		Individuo individuo4 = new Individuo(4);
		Individuo individuo5 = new Individuo(5);
		
		//INSTITUIÇÕES
		Instituicao instituicaoA = new Instituicao(individuo3);
		instituicaoA.add(individuo4);
		System.out.println("Total de participantes da instituição A: " + instituicaoA.totalParticipantes());
		System.out.print("Membros da instituicao A: ");
		for(Individuo i : instituicaoA.getMembros()) {
			System.out.print(i.getAssento() + " ");
		}
		
		Instituicao instituicaoB = new Instituicao(individuo2);
		instituicaoB.add(individuo5);
		System.out.println("\nTotal de participantes da instituição B: " + instituicaoB.totalParticipantes());
		System.out.print("Membros da instituicao B: ");
		for(Individuo i : instituicaoB.getMembros()) {
			System.out.print(i.getAssento() + " ");
		}
		
		//CONGRESSO
		Congresso congresso = new Congresso(individuo1);
		congresso.add(instituicaoA);
		congresso.add(instituicaoB);
		
		System.out.println("\n\nTotal de assentos no congresso: " + congresso.totalAssentos());
		System.out.println("Total de participantes: " + congresso.totalParticipantes());
	}
}
