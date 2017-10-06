void setup(void) {
  pinMode(A0, INPUT);   //fenyszenzor bemenete
  pinMode(13, OUTPUT);  //LEDek kimenete
  Serial.begin(9600);
}

void loop(void) {
  int fenyero = analogRead(A0);
  Serial.print("Fenyero = ");
  Serial.println(fenyero);

  if(fenyero < 500) {
      digitalWrite(13, HIGH);
    } else {
        digitalWrite(13, LOW);
      }
  delay(200);
