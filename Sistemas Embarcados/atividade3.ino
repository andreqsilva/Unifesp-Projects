#include "Servo.h"

const int LDR = A0;
int valorLido;

Servo servo;   // cria um objeto servo
int angulo;

void setup() {
  
  Serial.begin(9600);
  servo.attach(5);	// defino a entrada pwm do servo
  servo.write(0);
}

void loop() {

  valorLido = analogRead(LDR);
  //Serial.println(valorLido);
  angulo = map(valorLido,969,49,0,180);
  servo.write(angulo);
  Serial.println(angulo);
  
  delay(10);
}