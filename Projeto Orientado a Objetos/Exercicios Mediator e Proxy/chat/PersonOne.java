package chat;

public class PersonOne extends Colleague{
	public PersonOne(Mediator m) {
		super(m);
	}
	
	@Override
	public void receiveMessage(String message) {
		System.out.println("Pessoa 1 recebeu: " + message + "\n");
	}
}
