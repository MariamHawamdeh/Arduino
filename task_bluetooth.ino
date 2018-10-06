const int G = 13;
const int R = 12;
const int c =5;
char myPassword[] = { '1', '9', '9', '7','\0'};
int cnt =0;
char pass[c] = {'\0'};
void setup() {
pinMode(G,OUTPUT);
pinMode(R,OUTPUT);
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
pass[c] = {'\0'};
cnt =0;
}
 
