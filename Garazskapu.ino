#include <Servo.h>

#define trigPin 13
#define echoPin 6

Servo myServo1;
Servo myServo2;
int angle=30;
int flag=0;
int buzzerPin = 3;
int garazsLED = 12;
char message=' ';

void setup() {
  pinMode(garazsLED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo1.attach(9);
  myServo2.attach(10);
  Serial.begin(9600);
  myServo1.write(angle);
  myServo2.write(angle);
  delay(100);
}

void loop() {
  
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);
  if (distance <= 20){
    garazsnyit();
  }
    Serial.println(distance);
  delay(500);
}

void garazsnyit(){
 Serial.println("Garazs kapunyitas!");
      angle=30;
      flag=0;
      while(angle!=120) {
        angle+=1;
        Serial.println(angle);
        if (angle%20==0) {
          if(flag==0) {
            flag=1;
          } else {
            flag=0;
          }
        }
        myServo1.write(angle);
        myServo2.write(angle);
      
        if(flag==0) {
          digitalWrite(12, HIGH);
          analogWrite(buzzerPin, 10);
        }
        if(flag==1) {
          digitalWrite(12, LOW);
          analogWrite(buzzerPin ,0);
        }
        delay(40);
      }
      
      delay(5000);
  while(angle!=30) {
          angle-=1;
          myServo1.write(angle);
          myServo2.write(angle);
          Serial.println(angle);
          delay(40);
         }
}
