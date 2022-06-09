package factory;
import java.util.HashMap;
import java.util.Map;

public class FiguraFactory {
	private Map<String, Construtor> criadores = new HashMap<String, Construtor>();
	
	public FiguraFactory() {
		Construtor circuloBuilder = new CirculoBuilder();
		Construtor quadradoBuilder = new QuadradoBuilder();
		Construtor trianguloBuilder = new TrEquilateroBuilder();
		criadores.put("Circulo", circuloBuilder);
		criadores.put("Quadrado", quadradoBuilder);
		criadores.put("Triangulo", trianguloBuilder);
	}
	
	public Figura getFigura(double x, String key) {
		if(criadores.containsKey(key)) {
			return criadores.get(key).criaFigura(x).get();
		}
		return null;
	}
	
}
