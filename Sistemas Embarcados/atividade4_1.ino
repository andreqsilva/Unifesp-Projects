#include <Wire.h>

String comando;
char *ledOn = "LigarLed";
char *ledOff = "DesligarLed";
char *buzzerOn = "LigarBuzzer";
char *buzzerOff = "DesligarBuzzer";
char *LCD = "Display LCD";

void setup() {
	
  	Wire.begin();
  	Serial.begin(9600);
}

void lcdMessage() {
	
  	do {
    	if (Serial.available() > 0) {
        	do {
        		int character = Serial.read();
          		Wire.write(character);
          		delay(50);
          	}while(Serial.available() > 0);
          	break;
        }
    }while(1);
}

void buttonStatus() {
	
  	Wire.requestFrom(4,6); // request 6 bytes form slave device
  	if (Wire.available() > 0) {
  		int key = Wire.read();
      	if (key == 1) {
          Serial.println("Chave 1 ON");
          Serial.println("Chave 2 OFF");
        }
      	else if (key == 2) {
      		Serial.println("Chave 1 OFF");
          	Serial.println("Chave 2 ON");
        }
  	}
}

void loop() {
	
	Wire.beginTransmission(4);
  	
  	char vec[20] = "";
    comando = vec;
  
  	if (Serial.available() > 0) {
      	int i = 0;
      	
      	do {
          	char c = char(Serial.read());
        	vec[i] = c;
          	i++;
        }while(Serial.available() > 0);
      	comando = vec;
    }
  
  	if (comando == ledOn) {
      	Wire.write(1);
      	Wire.write(HIGH);
      	Serial.println("Led ligado");
  	}
  	else if (comando == ledOff) {
      	Wire.write(1);
      	Wire.write(LOW);
      	Serial.println("Led desligado");
  	}
  
  	if (comando == buzzerOn) {
  		Wire.write(2);
      	Wire.write(HIGH);
      	Serial.println("Buzzer ligado");
    }
  	else if (comando == buzzerOff) {
  		Wire.write(2);
      	Wire.write(LOW);
      	Serial.println("Buzzer desligado");
    }
  
  	if (comando == LCD) {
      	Serial.println("Digite a mensagem desejada");
      	Wire.write(3);
      	lcdMessage();
      	Serial.println("Mensagem alterada");
    }
   	
    Wire.endTransmission();
  	buttonStatus();
  
  	delay(500);
}