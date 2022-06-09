package state;

public class GatoQuantico {
	public final Estado VIVO = new EstadoVivo();
	public final Estado MORTO = new EstadoMorto();
	public final Estado QUANTICO = new EstadoQuantico();
	
	private Estado estado;
	
	public void setEstado(Estado estado) {
		this.estado = estado;
	}
	
	public void miar() {
		estado.miar();
	}
}
