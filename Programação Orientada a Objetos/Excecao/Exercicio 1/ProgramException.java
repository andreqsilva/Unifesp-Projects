package excecoes;
import java.lang.Exception;

public class ProgramException {
	public static void main(String args[]) {
		Exception message;
		try {
			message = new Exception("Erro");
		}
		catch(Exception ex) {
			System.out.println(ex.getMessage());
		}
		finally {
			System.out.println("Excecao verificada");
		}
	}
}