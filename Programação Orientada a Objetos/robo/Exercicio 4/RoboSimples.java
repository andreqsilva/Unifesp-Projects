package robo;

public class RoboSimples extends RoboAbstrato {
	RoboSimples(String n, int px, int py, short i) { 
		super(n, px, py, i); 
	} 
	public void move(int passos) { 
		switch (direcaoAtual()) { 
		case 0: 
			moveX(+passos); 
			break; 
		case 90: 
			moveY(+passos); 
			break; 
		case 180: 
			moveX(-passos); 
			break; 
		case 270: 
			moveY(-passos); 
			break; 
		} 
	}
	
	//exercicio 4
	public void mudaDirecao(short direcao) {
		if(direcao < 45 || direcao > 315) super.mudaDirecao((short)0);
		else if(direcao >= 45 && direcao < 135) super.mudaDirecao((short)90);
		else if(direcao >= 135 && direcao < 225) super.mudaDirecao((short)180);
		else if(direcao >= 225 && direcao < 315) super.mudaDirecao((short)270);
	}
	/*
	public static void main(String args[]) {
		RoboSimples robo = new RoboSimples("C3PO",0,0,(short)90);
		
		robo.move(10);
		System.out.println(robo.toString());
		
		robo.mudaDirecao((short)170);
		robo.move(10);
		
		System.out.println(robo.toString());
	}
	*/
}
