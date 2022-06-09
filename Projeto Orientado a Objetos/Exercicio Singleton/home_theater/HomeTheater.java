package home_theater;

public class HomeTheater {
	
	private CDPlayer cdPlayer = new CDPlayer();
	private Amplificador amplificador = new Amplificador();
	private DVDPlayer dvdPlayer = new DVDPlayer();
	private TelaProjecao tela = new TelaProjecao();
	private LuzAmbiente luzAmbiente = new LuzAmbiente();
	private MaquinaPipoca maquinaPipoca = new MaquinaPipoca();
	private MaquinaRefrigerante maquinaRefrigerante = new MaquinaRefrigerante();
	
	public HomeTheater() {}
	
	private static HomeTheater instancia;
	public static HomeTheater obterInstancia() {
		if(instancia == null) {
			instancia = new HomeTheater();
		}
		return instancia;
	}
	
	public void ouvirMusica(String nomeCD) {
		cdPlayer.colocarCD(nomeCD);
		cdPlayer.conectarAplificador(amplificador);
		cdPlayer.playCD();
	}
	
	public void aumentarVolume() {
		amplificador.aumentarVolume();
		System.out.println("Volume " + amplificador.getVolume());
	}
	
	public void diminuirVolume() {
		amplificador.diminuirVolume();
		System.out.println("Volume " + amplificador.getVolume());
	}
	
	public void assistirFilme(String nomeDVD) {
		dvdPlayer.colocarDVD(nomeDVD);
		tela.conectarDVD(dvdPlayer);
		tela.assistirDVD();
	}
	
	public void ligarDesligarLuz() {
		luzAmbiente.mudarEstado();
	}
	
	public void prepararMaquinas(double quantia, String marca){
		String[] refrigerantes = new String[5];
		refrigerantes[0] = "Coca";
		refrigerantes[1] = "Fanta";
		refrigerantes[2] = "Sprite";
		maquinaRefrigerante.setRefrigerante(refrigerantes);
		maquinaPipoca.colocarPipoca(quantia);
		maquinaPipoca.estourarPipoca();
		maquinaRefrigerante.pegarRefrigerante(marca);
	}
}
