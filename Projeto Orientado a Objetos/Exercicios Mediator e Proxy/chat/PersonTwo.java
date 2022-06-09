package chat;

public class PersonTwo extends Colleague{
	public PersonTwo(Mediator m) {
		super(m);
	}
	
	@Override
	public void receiveMessage(String message) {
		System.out.println("Pessoa 2 recebeu: " + message + "\n");
	}
}
