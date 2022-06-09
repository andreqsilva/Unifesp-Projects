const int led_1 = 13;
const int led_2 = 12;
const int led_3 = 11;
const int led_4 = 10;
const int led_5 = 9;
const int buzzer = 6;

const int sensorTemp = A0;
const int potPin = A1;

float temperatura;
int valorPot;
int timeDelay;

void setup() {
  
  Serial.begin(9600);
  pinMode(led_1,OUTPUT);
  pinMode(led_2,OUTPUT);
  pinMode(led_3,OUTPUT);
  pinMode(led_4,OUTPUT);
  pinMode(led_5,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(sensorTemp,INPUT);
}

float getTemperatura() {
  
  float valorSensor = analogRead(sensorTemp);
  float tensao = (valorSensor / 1024)*5; // define a tensao
  return (tensao-0.5)*100; // converte para °C  
}

void setEstadosLeds(int A, int B, int C, int D, int E) {
	
  digitalWrite(led_1,A);
  digitalWrite(led_2,B);
  digitalWrite(led_3,C);
  digitalWrite(led_4,D);
  digitalWrite(led_5,E);
}

void ledBuzzer() {
 
  digitalWrite(led_1,HIGH);
  digitalWrite(led_2,HIGH);
  digitalWrite(led_3,HIGH);
  digitalWrite(led_4,HIGH);
  digitalWrite(led_5,HIGH);
  tone(buzzer,1000);
  delay(timeDelay);
  
  digitalWrite(led_1,LOW);
  digitalWrite(led_2,LOW);
  digitalWrite(led_3,LOW);
  digitalWrite(led_4,LOW);
  digitalWrite(led_5,LOW);
  noTone(buzzer);
  delay(timeDelay);
}

void loop() {
  
  temperatura = getTemperatura();
  valorPot = analogRead(potPin);
  timeDelay = map(valorPot,0,1023,2,10) * 1000;
    
  Serial.println(temperatura);
  //Serial.println(timeDelay);
  
  //Serial.println(analogRead(sensorTemp));
  
  if (temperatura >= 25 && temperatura < 27) {
  	setEstadosLeds(HIGH,LOW,LOW,LOW,LOW); 
  }
  else if (temperatura >= 27 && temperatura < 29) {
  	setEstadosLeds(HIGH,HIGH,LOW,LOW,LOW);
  }
  else if (temperatura >= 29 && temperatura < 31) {
    setEstadosLeds(HIGH,HIGH,HIGH,LOW,LOW);
  }
  else if (temperatura >= 31 && temperatura < 33) {
  	setEstadosLeds(HIGH,HIGH,HIGH,HIGH,LOW);
  }
  else if (temperatura >= 33 && temperatura < 35) {
  	setEstadosLeds(HIGH,HIGH,HIGH,HIGH,HIGH);
  }
  else if (temperatura >= 35) {
  	ledBuzzer();
  }
  else {
  	setEstadosLeds(LOW,LOW,LOW,LOW,LOW);
  }
   
  delay(10);
}