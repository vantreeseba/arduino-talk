void output() {
  now = millis();
  controlTime = now - controlTimeOld; 
  if (controlTime > CONTROLREFRESH){
    controlTimeOld = now;
    controls();
  }    
}

void controls() {
  if (Connected) {

    MainControls(SASBIT, digitalRead(SASPIN));
    MainControls(RCSBIT, digitalRead(RCSPIN));
    MainControls(STAGEBIT, digitalRead(STAGEPIN));
    ControlGroups(1, digitalRead(CG1PIN));

    //This is an example of reading analog inputs to an axis, with deadband and limits
    CPacket.Throttle = constrain(map(analogRead(THROTTLEPIN),THROTTLEDB,1024-THROTTLEDB,0,1000),0, 1000);

    KSPBoardSendData(details(CPacket));
  }
}

void controlsInit() {
  pinMode(SASPIN, INPUT_PULLUP);
  pinMode(RCSPIN, INPUT_PULLUP);
  pinMode(CG1PIN, INPUT_PULLUP);
}

void MainControls(byte n, boolean s) {
  if (s)
    CPacket.MainControls |= (1 << n);       // forces nth bit of x to be 1.  all other bits left alone.
  else
    CPacket.MainControls &= ~(1 << n);      // forces nth bit of x to be 0.  all other bits left alone.
}

void ControlGroups(byte n, boolean s) {
  if (s)
    CPacket.ControlGroup |= (1 << n);       // forces nth bit of x to be 1.  all other bits left alone.
  else
    CPacket.ControlGroup &= ~(1 << n);      // forces nth bit of x to be 0.  all other bits left alone.
}


