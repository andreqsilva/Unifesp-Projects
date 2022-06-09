package robo;

public class RoboQueDeveVoltar extends RoboABateria{
	private int nro_passosX, nro_passosY;
	public RoboQueDeveVoltar(String n, int px, int py, short i, long e) { 
		super(n, px, py, i, e);
		nro_passosX = 0;
		nro_passosY = 0;
	}
	public void move(int passos) { 
		long energiaASerGasta = passos * 10;
		if (energiaASerGasta <= this.getEnergia()) { 
			switch (direcaoAtual()) { 
			case 0: 
				moveX(+passos);
				this.nro_passosX += passos;
				break; 
			case 45: 
				moveX(+passos); 
				moveY(+passos);
				this.nro_passosY += passos;
				this.nro_passosX += passos;
				break; 
			case 90: 
				moveY(+passos); 
				this.nro_passosY += passos;
				break; 
			case 135: 
				moveY(+passos); 
				moveX(-passos);
				this.nro_passosY += passos;
				this.nro_passosX -= passos;
				break; 
			case 180: 
				moveX(-passos); 
				this.nro_passosX -= passos;
				break; 
			case 225: 
				moveX(-passos); 
				moveY(-passos);
				this.nro_passosX -= passos;
				this.nro_passosY -= passos;
				break; 
			case 270: 
				moveY(-passos); 
				this.nro_passosY -= passos;
				break; 
			case 315: 
				moveY(-passos); 
				moveX(+passos); 
				this.nro_passosY -= passos;
				this.nro_passosX += passos;
				break; 
			} 
			this.setEnergia(getEnergia()-(long)energiaASerGasta);
		} 
	} 
	
	//exercicio 8
	public void retornaAOrigem() {
		if(Math.abs(this.nro_passosX)*10 <= this.getEnergia() && Math.abs(this.nro_passosY)*10 <= this.getEnergia()) {
			this.moveX(-this.nro_passosX);
			this.nro_passosX = 0;
			this.moveY(-this.nro_passosY);
			this.nro_passosY = 0;
		}
		else System.out.println("Sem energia suficiente");
	}
	
	public static void main(String args[]) {
		RoboQueDeveVoltar robo = new RoboQueDeveVoltar("Robo",10,10,(short)0,100);
		
		robo.move(5);
		System.out.println(robo.toString());
		
		robo.mudaDirecao((short)270);
		robo.move(1);
		System.out.println(robo.toString());
		robo.retornaAOrigem();
		System.out.println(robo.toString());

	}
}
