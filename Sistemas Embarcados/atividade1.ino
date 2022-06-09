const int buttonPin_1 = 2;
const int buttonPin_2 = 3;
const int buttonPin_3 = 4;

int buttonState_1;
int buttonState_2;
int buttonState_3;

int lastButtonState_1 = LOW;
int lastButtonState_2 = LOW;
int lastButtonState_3 = LOW;

const int ledGreenPin = 13;
const int ledYellowPin = 12;
const int ledRedPin = 11;

int ledGreenState = LOW;
int ledYellowState = LOW;
int ledRedState = LOW;

const int buzzerPin = 6;

int counterButton_1 = 0;
int counterButton_2 = 0;
int soma = 0;
int incLedTime = -1;
int incBuzzerTime = -1;

unsigned long lastDebounceTime_1 = 0;
unsigned long lastDebounceTime_2 = 0;
unsigned long lastDebounceTime_3 = 0;
unsigned long debounceDelay = 30;
unsigned long ledTime = 0;
unsigned long buzzerTime = 0;

int N = 3;  // número selecionado para a chave 3

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin_1, INPUT);
  pinMode(buttonPin_2, INPUT);
  pinMode(buttonPin_3, INPUT);
  pinMode(ledGreenPin, OUTPUT);
  pinMode(ledYellowPin, OUTPUT);
  pinMode(ledRedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  digitalWrite(ledGreenPin, ledGreenState);
  digitalWrite(ledYellowPin, ledYellowState);
  digitalWrite(ledRedPin, ledRedState);
}

void piscaLed() {

  if (millis() - ledTime < 2000 && incLedTime >= 0) {
    digitalWrite(ledRedPin, HIGH);
  } else digitalWrite(ledRedPin, LOW);

  if (millis() - ledTime > 2500 && incLedTime == 1) {
    ledTime = millis();
    incLedTime--;
  }

}

void tocaBuzzer() {

  if (millis() - buzzerTime < 2000 && incBuzzerTime >= 0) {
    tone(buzzerPin, 1000); // 1000Hz
  } else noTone(buzzerPin);

  if (millis() - buzzerTime > 2500 && incBuzzerTime == 1) {
    buzzerTime = millis();
    incBuzzerTime--;
  }

}

void loop() {
  int reading_1 = digitalRead(buttonPin_1);

  if (reading_1 != lastButtonState_1) {
    lastDebounceTime_1 = millis(); // reset
  }

  if (millis() - lastDebounceTime_1 > debounceDelay) {

    if (reading_1 != buttonState_1) {
      buttonState_1 = reading_1;

      if (buttonState_1 == HIGH) {
        counterButton_1 += 1;

        if (counterButton_1 % 2 == 0) {
          ledYellowState = HIGH;
        }
        else ledYellowState = LOW;
      }
    }
  }

  lastButtonState_1 = reading_1;

  int reading_2 = digitalRead(buttonPin_2);

  if (reading_2 != lastButtonState_2) {
    lastDebounceTime_2 = millis();
  }

  if (millis() - lastDebounceTime_2 > debounceDelay) {

    if (reading_2 != buttonState_2) {
      buttonState_2 = reading_2;

      if (buttonState_2 == HIGH) {
        counterButton_2 += 1;

        if (counterButton_2 % 2 != 0) {
          ledGreenState = HIGH;
        } else ledGreenState = LOW;
      }
    }
  }

  lastButtonState_2 = reading_2;

  int reading_3 = digitalRead(buttonPin_3);

  if (reading_3 != lastButtonState_3) {
    lastDebounceTime_3 = millis();
  }

  if (millis() - lastDebounceTime_3 > debounceDelay) {

    if (reading_3 != buttonState_3) {
      buttonState_3 = reading_3;

      if (buttonState_3 == HIGH) {
        soma = counterButton_1 + counterButton_2;
        ledTime = millis();

        if (soma % N == 0) {
          counterButton_1 = 0;
          counterButton_2 = 0;
          incLedTime = 0;
          ledGreenState = LOW;
          ledYellowState = LOW;
        }
        else {
          incLedTime = 1;
          incBuzzerTime = 1;
          buzzerTime = millis();
        }
      }
    }
  }

  lastButtonState_3 = reading_3;

  digitalWrite(ledGreenPin, ledGreenState);
  digitalWrite(ledYellowPin, ledYellowState);
  piscaLed();
  tocaBuzzer();

  Serial.print("counter_1=");
  Serial.println(counterButton_1);
  Serial.print("counter_2=");
  Serial.println(counterButton_2);
  
}
