package robo;

public class RoboPesadoABateria extends RoboABateria{
	private long peso;
	public RoboPesadoABateria(String n, int px, int py, short d, long e, long _peso) { 
		super(n, px, py, d, e); 
		peso = _peso;
	}
	public void move(int passos) { 
		double energiaASerGasta;
		//exercicio 7
		if(direcaoAtual() == 45 || direcaoAtual() == 135 || direcaoAtual() == 225 || direcaoAtual() == 315)
			energiaASerGasta = passos * 1.4 * this.peso;
		else energiaASerGasta = passos * this.peso;
		if (energiaASerGasta <= this.getEnergia()) { 
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
			this.setEnergia(getEnergia()-(long)energiaASerGasta);
		} 
	}
	/*
	public static void main(String args[]) {
		RoboPesadoABateria robo = new RoboPesadoABateria("BB-8",0,0,(short)135,100,5);
		
		robo.move(10);
		System.out.println(robo.toString());
	}
	*/
}
