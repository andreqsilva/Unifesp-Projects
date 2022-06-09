package strategy;
import java.util.Calendar;
import java.util.GregorianCalendar;

public class Agenda {
	private Calendar calendario = Calendar.getInstance();
	private Estrategia acao;
	private int day_of_week;
	
	public void definirEstrategia() {
		if(day_of_week >= calendario.SUNDAY && day_of_week <= calendario.TUESDAY) {
			acao = new ComecoSemana();
		}
		else if(day_of_week >= calendario.WEDNESDAY && day_of_week <= calendario.THURSDAY) {
			acao = new MeioSemana();
		}
		else {
			acao = new FinalSemana();
		}
	}
	
	public void setDayOfWeek(int day) {
		day_of_week = day;
	}
	
	public void statusSemanal() {
		acao.mensagem();
	}
	

}
