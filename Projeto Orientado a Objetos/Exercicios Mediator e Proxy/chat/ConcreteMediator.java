package chat;

public class ConcreteMediator implements Mediator{
	private Colleague personOne;
	private Colleague personTwo;
	
	public void setPersonOne(Colleague colleague) {
		personOne = colleague;
	}
	
	public void setPersonTwo(Colleague colleague) {
		personTwo = colleague;
	}
	
	public void sendMessage(String message, Colleague colleague) {
		if(personOne == colleague) {
			System.out.println("Pessoa 1 enviou: " + message);
			personTwo.receiveMessage(message);
		}
		else if(personTwo == colleague) {
			System.out.println("Pesoa 2 enviou: " + message);
			personOne.receiveMessage(message);
		}
	}
	
}
