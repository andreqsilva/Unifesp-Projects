package chat;

public class ChatRoom {
	public static void main(String[] args) {
		ConcreteMediator mediator = new ConcreteMediator();
		PersonOne personOne = new PersonOne(mediator);
		PersonTwo personTwo = new PersonTwo(mediator);
		
		mediator.setPersonOne(personOne);
		mediator.setPersonTwo(personTwo);
		
		personOne.sendMessage("Oi");
		personTwo.sendMessage("Olá");
		personTwo.sendMessage("Tudo bem com você?");
		personOne.sendMessage("Tudo sim. E com você?");
		personTwo.sendMessage("Estou bem também :)");
	}
}
