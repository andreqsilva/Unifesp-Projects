package robo;

public class RoboABateria extends RoboAbstrato{
	private long energia; 
	RoboABateria(String n, int px, int py, short d, long e) { 
		super(n, px, py, d); 
		energia = e; 
	} 
	public void move(int passos) { 
		long energiaASerGasta;
		//exercicio 5
		if(direcaoAtual() == 45 || direcaoAtual() == 135 || direcaoAtual() == 225 || direcaoAtual() == 315)
			energiaASerGasta = passos * 14;
		else energiaASerGasta = passos * 10;
		if (energiaASerGasta <= energia) { 
			switch (direcaoAtual()) { 
			case 0: 
				moveX(+passos); 
				break; 
			case 45: 
				moveX(+passos); 
				moveY(+passos); 
				break; 
			case 90: 
				moveY(+passos); 
				break; 
			case 135: 
				moveY(+passos); 
				moveX(-passos); 
				break; 
			case 180: 
				moveX(-passos); 
				break; 
			case 225: 
				moveX(-passos); 
				moveY(-passos); 
				break; 
			case 270: 
				moveY(-passos); 
				break; 
			case 315: 
				moveY(-passos); 
				moveX(+passos); 
				break; 
			} 
			energia -= energiaASerGasta; 
		} 
	} 
	
	//exercicio 1
	public void recarrega(long recarrega) {
		this.energia += recarrega;
	}
	
	public String toString() { 
		String resultado = super.toString() + "\n"; 
		resultado = resultado + "Energia do robô:" + energia; 
		return resultado; 
	}
	
	//para o exercicio 7
	protected long getEnergia() {
		return this.energia;
	}
	
	protected void setEnergia(long _energia) {
		this.energia = _energia;
	}
	
	/*
	public static void main(String args[]) {
		RoboABateria robo = new RoboABateria("R2-D2",0,0,(short)135,100);
		
		robo.move(1);
		System.out.println(robo.toString());
		
	}
	*/
	
}
