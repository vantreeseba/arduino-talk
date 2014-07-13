/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
 
 This example code is in the public domain.
 */

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

int blinkTime = 0;
boolean ledOn = false;
// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(10);        // delay in between reads for stability
  blinkLed(sensorValue);
}

void blinkLed(int value){
  
  if(blinkTime > value){
    ledOn = !ledOn;
    if(ledOn){
      digitalWrite(13,LOW);
    } else {
      digitalWrite(13,HIGH);
    }
    blinkTime = 0;
  }
  
  blinkTime = blinkTime + 10;
}
