/*
 * Ez az app kezelte az Arduino oldalarol a bejovo-kimeno jeleket, tartotta a kapcsolatot a mobillal.
 */


int incomingByte = 0;   // bejovo adatok

void setup() {
  Serial.begin(9600);
  pinMode(13, HIGH);
}

void loop() {

  if (Serial.available() > 0) {
    incomingByte = Serial.parseInt();
    if (incomingByte == 1) {
      digitalWrite(13, HIGH);
    } else if (incomingByte == 2) {
      digitalWrite(13, false);
    }
    Serial.println(incomingByte, DEC);
  }
}
