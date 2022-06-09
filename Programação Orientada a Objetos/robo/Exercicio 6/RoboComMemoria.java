package robo;

public class RoboComMemoria extends RoboAbstrato {
	private int nro_passosX, nro_passosY;
	public RoboComMemoria(String n, int px, int py, short i) { 
		super(n, px, py, i);
		nro_passosX = 0;
		nro_passosY = 0;
	} 
	public void move(int passos) { 
		switch (direcaoAtual()) { 
		case 0: 
			moveX(+passos);
			nro_passosX += passos;
			break; 
		case 90: 
			moveY(+passos);
			nro_passosY += passos;
			break; 
		case 180: 
			moveX(-passos);
			nro_passosX -= passos;
			break; 
		case 270: 
			moveY(-passos); 
			nro_passosY -= passos;
			break; 
		} 
	}
	
	//exercicio 6
	public void retornaAOrigem() {
		this.moveX(-this.nro_passosX);
		this.nro_passosX = 0;
		this.moveY(-this.nro_passosY);
		this.nro_passosY = 0;
	}
	
	/*
	public static void main(String args[]) {
		RoboComMemoria robo = new RoboComMemoria("Bender",10,10,(short)0);
		
		robo.move(10);
		System.out.println(robo.toString());
		
		robo.mudaDirecao((short)270);
		robo.move(10);
		System.out.println(robo.toString());
		
		robo.retornaAOrigem();
		System.out.println(robo.toString());
		
		robo.move(20);
		System.out.println(robo.toString());
		
		robo.retornaAOrigem();
		System.out.println(robo.toString());

	}
	*/
	
}

