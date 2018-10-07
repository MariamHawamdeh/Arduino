const int G = 13;
const int R = 12;
const int c =5;
char myPassword[] = { '1', '9', '9', '7','\0'};
int cnt =0;
char pass[c] = {'\0'};
const int buzzer = 10;
int motorPin =  5;    
    

void setup() {
pinMode(G,OUTPUT);
pinMode(R,OUTPUT);
pinMode(buzzer, OUTPUT);
Serial.begin(9600);
}

void loop() {

if(Serial.available())
{
  for (int i=0; i<c;i++)
 { pass[i] = Serial.read();
 }
  for (int j=0; j<c;j++)
 {if(pass[j] == myPassword[j])
 cnt++;
 }
 if(cnt==c-1)
 {digitalWrite(G,HIGH);
  digitalWrite(R,LOW);
  analogWrite(motorPin, 90); //rotates motor
   // set the Pin motorPin1 LOW
  
    // set the Pin motorPin2 LOW
  tone(buzzer, 2000,100); // tone( pin number, frequency in hertz, duration in milliseconds);
  delay(1000);        // ...for 1 sec
  noTone(buzzer);
  delay(4000); // Stop sound...
  digitalWrite(motorPin, LOW); 
  }
  else 
  { digitalWrite(R,HIGH);
  digitalWrite(G,LOW);
  tone(buzzer, 1000,1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
       
  }
}
else 
{
  digitalWrite(G,LOW);
  digitalWrite(R,LOW); 
}
delay(1000);
pass[c] = {'\0'};
cnt =0;
}
 
