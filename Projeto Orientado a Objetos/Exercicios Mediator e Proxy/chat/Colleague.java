package chat;

public abstract class Colleague {
	private Mediator mediator;
	
	public Colleague(Mediator m) {
		mediator = m;
	}
	
	public void sendMessage(String message) {
		mediator.sendMessage(message, this);
	}
	
	public abstract void receiveMessage(String message);
}
