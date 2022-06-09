package exercicios_heranca;
import java.util.ArrayList;

public class Banco {
	ArrayList<Conta> contas = new ArrayList<>();
	public void atualiza() {
		for(int i = 0; i < this.contas.size(); i++) {
			this.contas.get(i).update();
		}
	}
	
	public static void main(String[] args) {	
		Banco nubank = new Banco();

		ContaCorrente c1 = new ContaCorrente(1234);
		ContaPoupanca c2 = new ContaPoupanca(3541);
		ContaCorrente c3 = new ContaCorrente(4210);
		
		c1.credita(1000);
		c2.credita(2000);
		c3.credita(5000);
		
		c1.debita(500);
		c3.debita(6001); // estoura o limite
		
		c2.adcionaJuros(0.5);
				
		nubank.contas.add(c1);
		nubank.contas.add(c2);
		nubank.contas.add(c3);
		
		for(int i = 0; i < nubank.contas.size(); i++) {
			nubank.contas.get(i).imprime();
		}
	
		nubank.atualiza();
	}
}
