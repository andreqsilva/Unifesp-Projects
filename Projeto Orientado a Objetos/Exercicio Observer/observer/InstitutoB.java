package observer;

public class InstitutoB implements Observer{
	private Observable monitoramentoTemperatura, monitoramentoPressao;
	private double temperatura, pressaoAtmosferica;
	
	public InstitutoB(Observable dadoMonitoramento) {
		addData(dadoMonitoramento);
	}
	
	public void addData(Observable dadoMonitoramento) {
		if(dadoMonitoramento instanceof PressaoAtmosferica) {
			this.monitoramentoPressao = dadoMonitoramento;
			monitoramentoPressao.add(this);
		}
		else if(dadoMonitoramento instanceof Temperatura) {
			this.monitoramentoTemperatura = dadoMonitoramento;
			monitoramentoTemperatura.add(this);
		}
	}
	
	public double getPressaoAtmosferica() {
		return pressaoAtmosferica;
	}
	
	public double getTemperatura() {
		return temperatura;
	}
	
	@Override
	public void update(Observable o) {
		if(o instanceof PressaoAtmosferica) {
			System.out.println("Atualizando a pressão atmosférica do instituto B...");
			PressaoAtmosferica data = (PressaoAtmosferica)o;
			pressaoAtmosferica = data.getData();
		}
		else if(o instanceof Temperatura) {
			System.out.println("Atualizando temperatura do instituto B...");
			Temperatura data = (Temperatura)o;
			temperatura = data.getData();
		}
	}
}
