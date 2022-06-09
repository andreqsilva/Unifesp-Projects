package home_theater;

public class LuzAmbiente {
	private boolean estado;
	public LuzAmbiente() {
		estado = false;
	}
	
	public boolean getEstado() {
		return estado;
	}
	
	public void mudarEstado() {
		if(estado == true) {
			estado = false;
			System.out.println("Desligando luz ambiente...");
		}
		else {
			estado = true;
			System.out.println("Ligando luz ambiente...");
		}
	}
}
