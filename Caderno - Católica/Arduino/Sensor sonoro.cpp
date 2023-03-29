const int led = 2, sensor = 12;
const int buzzer = 13;

void setup(){
    pinMode(led, OUTPUT);
    pinMode(buzzer, OUTPUT);
}

void loop() {
  int cm = distancia.ping_cm();
  Serial.print("Distancia em cm: "); 
  Serial.println(cm);

  if(cm > 55  && cm <= 60){
    NewTone(nota, 264); // 264Hz (Dó)
    }
   else if (cm > 50 && cm <= 55){
    NewTone(nota, 297); // 297Hz (Ré)
    }
   else if (cm > 45 && cm <= 50){
    NewTone(nota, 330); // 330Hz (Mi)
    }
   else if (cm > 40 && cm <= 45){
    NewTone(nota, 352); // 352Hz (Fá)
    }
   else if (cm > 35 && cm <= 40){
    NewTone(nota,396); // 396Hz (Sol)
    }
   else if (cm > 30 && cm <= 35){
    NewTone(nota,440); // 440Hz (Lá)
    }
   else if (cm > 25 && cm <= 30){
    NewTone(nota,495); // 495Hz (Si)
    } 
   else if (cm > 20 && cm <= 25){
    NewTone(nota,528); // 528Hz (Dó)
    }  
   else {
    noNewTone(nota); 
        }
       delay(50);
    }
