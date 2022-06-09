package strategy;
import java.util.Calendar;

public class Aplicacao {
	public static void main(String[] args) {
		Agenda agenda = new Agenda();
		
		agenda.setDayOfWeek(Calendar.MONDAY);
		agenda.definirEstrategia();
		agenda.statusSemanal();
		
		agenda.setDayOfWeek(Calendar.WEDNESDAY);
		agenda.definirEstrategia();
		agenda.statusSemanal();
		
		agenda.setDayOfWeek(Calendar.FRIDAY);
		agenda.definirEstrategia();
		agenda.statusSemanal();
	}
}
