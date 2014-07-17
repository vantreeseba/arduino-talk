void Indicators() {
  caution = VData.G > GCAUTION || VData.LiquidFuelS/VData.LiquidFuelTotS*100 < FUELCAUTION;
  warning = VData.G > GWARN || VData.LiquidFuelS/VData.LiquidFuelTotS*100 < FUELWARN;

  digitalWrite(YLED,caution);
  digitalWrite(RLED,warning);
}

void initLEDS() {
  pinMode(GLED,OUTPUT);
  digitalWrite(GLED,HIGH);

  pinMode(YLED,OUTPUT);
  digitalWrite(YLED,HIGH);

  pinMode(RLED,OUTPUT);
  digitalWrite(RLED,HIGH);
}

void LEDSAllOff() {
  digitalWrite(GLED,LOW);
  digitalWrite(YLED,LOW);
  digitalWrite(RLED,LOW);
}


void InitTxPackets() {
  HPacket.id = 0;  
  CPacket.id = 1;
}








