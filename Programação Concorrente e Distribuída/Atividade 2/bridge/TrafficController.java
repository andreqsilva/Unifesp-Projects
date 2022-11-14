/*
  André Fernando Quaresma da Silva
  Jonatas Carrocine
*/

public class TrafficController {
  boolean libera = true;

  public synchronized void enterBridge() {
    try {
      while (!libera) wait(); // bloqueia a thread
        libera = false;
    } catch (InterruptedException ie) {
      System.err.println(ie.toString());
    }
  }

  public synchronized void leaveBridge() {
    libera = true;
    notifyAll(); // libera todas as threads
  }

  /*
  public void enterLeft() {
    System.out.println("enterLeft");
  }

  public void enterRight() {
	 System.out.println("enterRight");
  }

  public void leaveLeft() {
	 System.out.println("leaveLeft");
	}

  public void leaveRight() {
	 System.out.println("leveRight");
	}
  */
}
