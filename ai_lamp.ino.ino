const int ledPin = 3;  
const int potPin = A1;  
const int buttonPin = 2; 
const int ldrPin = A0;  

void setup() { 
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  pinMode(buttonPin, INPUT);
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);  // initialize serial communication at 9600 bps
}

void loop() {
  // read potentiometer value and adjust LED brightness
  int potValue = analogRead(potPin);
  int ledValue = map(potValue, 0, 1023, 0, 255);
  analogWrite(ledPin, ledValue);

  // if button is pressed, print values to serial monitor
  if (digitalRead(buttonPin)) {
    int ldrValue = analogRead(ldrPin);
    Serial.print(ldrValue);
    Serial.print(",");
    Serial.print(ledValue);
    Serial.println();
  }
  delay(750);
}
