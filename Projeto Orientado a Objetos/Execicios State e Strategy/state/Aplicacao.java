package state;

public class Aplicacao {
	public static void main(String[] args) {
		GatoQuantico gato = new GatoQuantico();
		
		gato.setEstado(gato.VIVO);
		gato.miar();
		
		gato.setEstado(gato.MORTO);
		gato.miar();
		
		gato.setEstado(gato.QUANTICO);
		gato.miar();
	}
}
