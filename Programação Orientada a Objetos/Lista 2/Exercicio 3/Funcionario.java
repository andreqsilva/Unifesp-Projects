package lista;
import java.util.ArrayList;

public class Funcionario {
	private String sobreNome;
	private String nome;
	private double salarioHora;
	private int anosNaEmpresa;
	public Funcionario(String _sobreNome, String _nome, double salario, int anos) {
		this.sobreNome = _sobreNome;
		this.nome = _nome;
		this.salarioHora = salario;
		this.anosNaEmpresa = anos;
	}
	
	static void imprimeX(Funcionario funcionarios[], int X) {
		int i;
		for (i = 0; i < funcionarios.length; i++) { 
			if(funcionarios[i].anosNaEmpresa >= X) {
				System.out.print(funcionarios[i].nome + " ");
				System.out.print(funcionarios[i].sobreNome + " ");
				System.out.println(funcionarios[i].salarioHora);
			}
		}
	}
	
	public static void main(String args[]) {
		//ArrayList<Object> funcionarios = new ArrayList<Object>();
		Funcionario[] funcionarios = new Funcionario[4];

		funcionarios[0] = new Funcionario("Silva","Andre",2000,10);
		funcionarios[1] = new Funcionario("Fernandes","Rodrigo",1000,5);
		funcionarios[2] = new Funcionario("Santos","Andriane",2500,15);
		funcionarios[3] = new Funcionario("Lopes","Angela",2000,8);
		
		imprimeX(funcionarios,10);
	}
}
