package observer;
import java.util.ArrayList;
import java.util.Iterator;

public class InstitutoA implements Observer{
	private Observable monitoramentoPH, monitoramentoTemperatura;
	private double ph, temperatura;
	
	public InstitutoA(Observable dadoMonitoramento) {
		addData(dadoMonitoramento);
	}
	
	public void addData(Observable dadoMonitoramento) {
		if(dadoMonitoramento instanceof PH) {
			this.monitoramentoPH = dadoMonitoramento;
			monitoramentoPH.add(this);
		}
		else if(dadoMonitoramento instanceof Temperatura) {
			this.monitoramentoTemperatura = dadoMonitoramento;
			monitoramentoTemperatura.add(this);
		}
	}
	
	public double getPH() {
		return ph;
	}
	
	public double getTemperatura() {
		return temperatura;
	}
	
	@Override
	public void update(Observable o) {
		if(o instanceof PH) {
			System.out.println("Atualizando pH do instituto A...");
			PH data = (PH)o;
			ph = data.getData();
		}
		else if(o instanceof Temperatura) {
			System.out.println("Atualizando temperatura do instituto A...");
			Temperatura data = (Temperatura)o;
			temperatura = data.getData();
		}
	}
}
