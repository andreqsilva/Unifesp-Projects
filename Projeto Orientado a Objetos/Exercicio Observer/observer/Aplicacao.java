package observer;

public class Aplicacao {
	public static void main(String args[]) {
		int i;
		PH ph = new PH();
		Temperatura temperatura = new Temperatura();
		PressaoAtmosferica pressaoAtmosferica = new PressaoAtmosferica();
		
		// o instituo A monitora pH e temperatura
		InstitutoA institutoA = new InstitutoA(ph);
		institutoA.addData(temperatura);
		
		// o instituto B monitora temperatura e pressão atmosférica
		InstitutoB institutoB = new InstitutoB(temperatura);
		institutoB.addData(pressaoAtmosferica);
		
		for(i = 0; i < 5; i++) {
			ph.setData(3.2 + i);	//definindo novo ph
			temperatura.setData(16.5 + i);	//nova temperatura
			pressaoAtmosferica.setData(1 + i); //novo pressao atmosferica
			
			System.out.println("pH = " + ph.getData());
			System.out.println("pH monitorado pelo instituto A: " + institutoA.getPH());
			
			System.out.println("Temperatura = " + temperatura.getData());
			System.out.println("Temperatura monitorada pelo instituto A: " + institutoA.getTemperatura());
			System.out.println("Temperatura monitorada pelo instituto B: " + institutoB.getTemperatura());
			
			System.out.println("Pressão atmosférica = " + pressaoAtmosferica.getData());
			System.out.println("Pressão atmosférica monitorada pelo instituto B: " + institutoB.getPressaoAtmosferica() + "\n");
		}
	}
}
