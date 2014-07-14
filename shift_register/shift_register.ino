int loadPin = 6;
int clockPin = 7;
int dataPin = 8;
int ledPin = 13;

int bitOrder = MSBFIRST;
byte value = 0;

void setup() { 
  pinMode(loadPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, INPUT);
  pinMode(ledPin, OUTPUT); 
  
  digitalWrite(clockPin, HIGH);
  Serial.begin(9600);
}

void loop() {
  loadData(loadPin, clockPin);
  value = readData(dataPin, clockPin);
  

  if(value & 1){
    Serial.println("button pushed");
  }
  
  if(value & 2){
    Serial.println("switch on");
  }
  
  if(value == 0){
    Serial.println("nothing on");
  }
    

  delay(1);        // delay in between reads for stability
}

void loadData(int loadPin, int clockPin){
  digitalWrite(clockPin, HIGH);
  digitalWrite(loadPin,HIGH);
  delayMicroseconds(1);
  digitalWrite(clockPin, LOW);
  digitalWrite(loadPin, LOW);
  delayMicroseconds(1);
  digitalWrite(clockPin, HIGH);
  delayMicroseconds(5);
}

byte readData(int dataPin, int clockPin){
  byte data = 0;
  long bitVal = 0;
  
  for(int i = 0; i < 8; i++){
    bitVal = digitalRead(dataPin);

        /* Set the corresponding bit in bytesVal.
        */
        data |= (bitVal << ((8-1) - i));

        /* Pulse the Clock (rising edge shifts the next bit).
        */
        digitalWrite(clockPin, HIGH);
        delayMicroseconds(5);
        digitalWrite(clockPin, LOW);
  }
  
  return data;
}

