// C++ code
//
const int vermelho = 12;
const int verde = 6;
const int amarelo = 10;
const int ledv = 4;
const int ledve = 1;

void setup(){
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(ledv, OUTPUT);
  pinMode(ledve, OUTPUT);
}

void loop(){
  digitalWrite(vermelho, HIGH);
  digitalWrite(amarelo, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(ledve,HIGH);
  digitalWrite(ledv,LOW);
  delay(1000);

  digitalWrite(vermelho, LOW);
  digitalWrite(amarelo, HIGH);
  digitalWrite(verde, LOW);
  digitalWrite(ledve,LOW);
  digitalWrite(ledv,HIGH);
  delay(1000);

  digitalWrite(vermelho, LOW);
  digitalWrite(amarelo, LOW);
  digitalWrite(verde, HIGH);
  digitalWrite(ledve,LOW);
  digitalWrite(ledv,HIGH);
  delay(1000);
}