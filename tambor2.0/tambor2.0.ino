#define tambor A0
#define ledAviso 3
#define aviso 8
#define pinAcierto 7

bool estadoT = false;
bool estadoS = false;

int ledR = 13;
int ledA = 11;
int ledV = 10;
int contAc = 0;

int dato;

void setup() {
  Serial.begin(9600);
  pinMode(tambor, INPUT);
  pinMode(aviso, INPUT);

  pinMode(pinAcierto, OUTPUT);
  pinMode(ledAviso, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledV, OUTPUT);

  digitalWrite(pinAcierto, LOW);
  digitalWrite(ledR, LOW);
  digitalWrite(ledA, LOW);
  digitalWrite(ledV, LOW);
}

void loop() {
  estadoS = digitalRead(aviso);
  estadoT = digitalRead(tambor);

  if (estadoT == true && estadoS == true) {
    fade();
    digitalWrite(pinAcierto, HIGH);
  } else {
    digitalWrite(pinAcierto, LOW);
  }

  //  if (contAc > 10) {
  //  }
  //  if (contAc > 20) {
  //  }
  //  if (contAc > 30) {
  //  }
  //  if (contAc > 31) {
  //    contAc = 0;
  //  }
}

void fade() {
  for (int i = 0; i < 255; i++) {
    analogWrite(ledAviso, i);
    delay(1);
  }
  for (int i = 255; i > 0; i--) {
    analogWrite(ledAviso, i);
    if (i <= 1) {
      i = 0;
    }
  }
  contAc += 1;
  Serial.println(contAc);

  //delay(1);
}



