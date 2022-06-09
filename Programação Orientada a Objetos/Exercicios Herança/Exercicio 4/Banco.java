package exercicios_heranca;
import java.util.ArrayList;

public class Banco {
	ArrayList<Conta> contas = new ArrayList<>();
	public void atualiza() {
		for(int i = 0; i < this.contas.size(); i++) {
			this.contas.get(i).update();
		}
	}
	
	public void abrirContaCorrente(int _numero) {
		ContaCorrente c = new ContaCorrente(_numero);
		this.contas.add(c);
	}
	
	public void abrirContaPoupanca(int _numero, double _juros) {
		ContaPoupanca c = new ContaPoupanca(_numero);
		c.adcionaJuros(_juros);
		this.contas.add(c);
	}
	
	public void fecharConta(int index) {
		this.contas.remove(index);
		System.out.println("Conta fechada");
	}
	
	public void pagarDividendo(int index, double percent) {
		double dividendo = this.contas.get(index).getSaldo()*percent;
		this.contas.get(index).credita(dividendo);
		System.out.println("Valor do dividendo " + dividendo);
	}

	public static void main(String[] args) {	
		Banco nubank = new Banco();
		nubank.abrirContaCorrente(1234);
		nubank.abrirContaPoupanca(4172, 0.7);
		
		nubank.contas.get(0).credita(1500);
		nubank.contas.get(1).credita(2310);
		
		for(int i = 0; i < nubank.contas.size(); i++) {
			nubank.contas.get(i).imprime();
		}
		nubank.atualiza();
		
		nubank.fecharConta(1);
		for(int i = 0; i < nubank.contas.size(); i++) {
			nubank.contas.get(i).imprime();
		}
		nubank.pagarDividendo(0, 0.3);	
	}
}
