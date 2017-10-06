int fenyero1e;
int fenyero1u;
int fenyero2e;
int fenyero2u;
int a = 0;        //letszam 0
unsigned long ido1;
unsigned long ido2;

void setup()
{
  for (int i = 4 ; i < 12 ; i++){   //a 7szegmenses számkijelzoket kimenetre allitja
    pinMode(i, OUTPUT);
  }
       pinMode(13, OUTPUT);        //a szobai lampat kimenetre allitja

        Serial.begin(9600);   
}

void loop(){

fenyero1u = fenyero1e ;
fenyero2u = fenyero2e ;

  fenyero1e = 1023 - analogRead(A0); 
  fenyero2e = 1023 - analogRead(A1); 

  Serial.print("fenyero 1 = ");
  Serial.println(fenyero1e); 
  Serial.print("fenyero 2 = ");
  Serial.println(fenyero2e);

     if(fenyero1e - fenyero1u > 50) {
        ido1 = millis() ;
     }
    if(fenyero2e - fenyero2u > 50) {
        ido2 = millis() ;
    }

    Serial.print("Ido1: ");
      Serial.println(ido1);

    Serial.print("Ido2: ");
     Serial.println(ido2);
//darabszam novelo
delay(10);
    if(ido1 != 0 and ido2 != 0) {
          if(ido1 > ido2) {
              //hozzaad egyet
              a+=1;
              Serial.println("+1");
          } else if(a>0){
               //levon egyet
               a-=1;
               Serial.println("-1");
            }
            ido1 = 0 ;    //visszaallit
            ido2 = 0 ;
    }
    Serial.println(a);
    displayDigit(a);
    if (a==0){
      digitalWrite(13,LOW);
    }
    else{
      digitalWrite(13,HIGH);
    }
}

void displayDigit(int num){   //a 7szegmenses kulonbozo allapotai leirva
  
  if (num == 0){
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
  if (num == 1){
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
  if (num == 2){
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
  }
  if (num == 3){
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
  if (num == 4){
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
  if (num == 5){
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
  if (num == 6){
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
  if (num == 7){
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
  if (num == 8){
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
  if (num == 9){
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
}
