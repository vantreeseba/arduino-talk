int buttonPin = 7;
int ledPin = 13;
int buttonPressed = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);  
}


void loop() {
  delay(10);        // delay in between reads for stability
  buttonPressed = digitalRead(buttonPin);
  digitalWrite(ledPin, buttonPressed);
}
