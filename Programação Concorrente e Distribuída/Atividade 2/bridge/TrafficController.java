public class TrafficController {
  boolean libera = true;

  public synchronized void enterBridge() {
    try {
      while (!libera) wait();
        libera = false;
    } catch (InterruptedException ie) {
      System.err.println(ie.toString());
    }
  }

  public synchronized void leaveBridge() {
    libera = true;
    notifyAll();
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
