char t;

void setup() {
  pinMode(13, OUTPUT);  //motores esquerdos frente
  pinMode(12, OUTPUT);  //motores esquerdos tras
  pinMode(11, OUTPUT);  //motores direito frente
  pinMode(10, OUTPUT);  //motores direit tras

  Serial.begin(9600);

}

void loop() {
  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);
  }

  if (t == '1') {          //move para frente(todos os motores giram na direção direta)
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
  }

  else if (t == '2') {    //move para tras(todos os motores giram na direção inversa)
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
  }

  else if (t == '3') {    //vira a direita (motores do lado esquerdo giram na direção para a frente, motores do lado direito não giram)
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
  }

  else if (t == '4') {    //vira a esquerda (motores do lado direito giram na direção para a frente, motores do lado esquerdo não giram)
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
  }

  else if (t == '5') {    //para (todos os motores param)
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
  }
  delay(100);
}
