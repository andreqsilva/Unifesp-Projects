#include <Wire.h>
#include <LiquidCrystal.h>

const int buttonA = 9;
const int buttonB = 8;
const int LED = 10;
const int buzzer = 6;

bool estadoLed = LOW;
bool estadoBuzzer = LOW;
bool estadoButtonA = LOW;
bool estadoButtonB = LOW;

int flagA = 0;
int flagB = 0;

LiquidCrystal lcd(12,11,5,4,3,2); // modo 4 bits
int x, y;

void setup() {
  
  	pinMode(LED,OUTPUT);
  	pinMode(buzzer,OUTPUT);
  	Wire.begin(4);
  	Wire.onReceive(receiveEvent);
  	Wire.onRequest(requestEvent);
	lcd.begin(16,2);
}

void receiveEvent(int howMany) {
	
  	if (Wire.available() > 1) {
      	int tipoComando = Wire.read();
    	if (tipoComando == 1) {
      		estadoLed = Wire.read();
      	}
      	
      	if (tipoComando == 2) {
      		estadoBuzzer = Wire.read();
        }
      
      	if (tipoComando == 3) {
          	x = 0;
          	y = 0;
          	lcd.clear();
          	while(Wire.available() > 0) {
          		int character = Wire.read();
              	lcd.print(char(character));
                x += 1;
                y += 1;
                if (x > 15) {
                    lcd.setCursor(0,1);
                    x = 0;
                }
                if (y > 31) {
                    lcd.setCursor(0,0);
                    y = 0;
                    x = 0;
                } 	
            }
      	}
    }
}

void buttonState() {
	
  	estadoButtonA = digitalRead(buttonA);
  	estadoButtonB = digitalRead(buttonB);
  	
  	if (estadoButtonA == HIGH && flagA == 0) flagA = 1;
  	if (estadoButtonA == LOW && flagA == 1) flagA = 0;
  
  	if (estadoButtonB == HIGH && flagB == 0) flagB = 1;
  	if (estadoButtonB == LOW && flagB == 1) flagB = 0;
}

void requestEvent() {
  
  	if (flagA == 1) {
  		Wire.write(1);
    }
  	if (flagB == 1) {
 		Wire.write(2);
  	}
}

void loop() {
  	
  	buttonState();
  
  	if (estadoBuzzer == HIGH) {
  		tone(buzzer,1000);
  	}
  	else noTone(buzzer);
  
  	digitalWrite(LED,estadoLed);
  	
  	delay(100);
}