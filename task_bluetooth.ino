const int G = 13; // Green LED with pin 13
const int R = 12; // Red LED with pin 12
const int c =5; // 5 elements in the array
char myPassword[] = { '1', '9', '9', '7','\0'}; // PIN 
int cnt =0; // counter
char pass[c] = {'\0'}; // array for the entered PIN
void setup() {
pinMode(G,OUTPUT);
pinMode(R,OUTPUT);
Serial.begin(9600); // bluetooth serial
}

void loop() {

if(Serial.available())
{
  for (int i=0; i<c;i++) // read the entered PIN 
 { pass[i] = Serial.read();
 }
  for (int j=0; j<c;j++) // compare the entered PIN with  myPassword[]
 {if(pass[j] == myPassword[j])
 cnt++; // if the digit correct increment to the counter 
 }
 if(cnt==c-1)   // if the 4 digits entered are correct light up the green LED
 {digitalWrite(G,HIGH);
  digitalWrite(R,LOW);}
  else 
  { digitalWrite(R,HIGH);
  digitalWrite(G,LOW);
  }
}
else  
{
  digitalWrite(G,LOW);
  digitalWrite(R,LOW); 
}
delay(1000); 
pass[c] = {'\0'}; // clear the array 
cnt =0; // reset the counter
  
}
 
