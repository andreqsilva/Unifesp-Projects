package home_theater;

public class MaquinaRefrigerante {
	private String[] refrigerante = new String[5];

	public MaquinaRefrigerante() {
		this.refrigerante = null;
	}

	public void setRefrigerante(String[] refrigerante) {
		this.refrigerante = refrigerante;
	}
	
	public String[] getRefrigerantes() {
		return refrigerante;
	}
	
	public void pegarRefrigerante(String marca) {
		for(String r : refrigerante) {
			if(r == marca) {
				System.out.println("Colocando " + marca + " no copo...");
				return;
			}
		}
		System.out.println("Marca não disponível");
	}
}
