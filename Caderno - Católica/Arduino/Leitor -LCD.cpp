void setup(){
    Serial.begin(9600);
}

void loop(){
    int vel = analogRead(A0);
    Serial.println(vel);
    delay(500);
}