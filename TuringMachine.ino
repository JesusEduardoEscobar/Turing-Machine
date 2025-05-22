int RPWM = 5;
int LPWM = 6;

const int s0 = 8;
const int s1 = 9;
const int s2 = 12;
const int s3 = 11;
const int out = 10;

char letra = 'd'; // Último símbolo leído
String estado = "q0"; // Estado inicial

void setup() {
  Serial.begin(9600);
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);

  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
  Serial.println("Estado: " + estado);
}

void loop() {
  avanzar();
  leerColor();
  transicion();
  delay(1000);
}

void avanzar() {
  analogWrite(RPWM, 100);
  analogWrite(LPWM, 0);
  delay(1000);
  analogWrite(RPWM, 0);
}

void retroceder() {
  analogWrite(LPWM, 100);
  analogWrite(RPWM, 0);
  delay(1000);
  analogWrite(LPWM, 0);
}

void leerColor() {
  int R = getRojo();
  int V = getVerde();
  int A = getAzul();

  if (R > 37 && R < 52 && V > 29 && V < 48 && A > 18 && A < 34) {
    letra = 'a';
  } else if (R > 99 && R < 167 && V > 131 && V < 234 && A > 97 && A < 188) {
    letra = 'c';
  } else if (R > 16 && R < 26 && V > 57 && V < 84 && A > 29 && A < 48) {
    letra = 'b';
  }
  Serial.println("Símbolo leído: " + String(letra));
}

void transicion() {
  Serial.println("Estado: " + estado);
  if (estado == "q0") {
    if (letra == 'c') {
      estado = "q1";
    } else {
      estado = "q_dead";
    }
  } else if (estado == "q1") {
    if (letra == 'a') {
      estado = "q2";
    } else {
      estado = "q_dead";
    }
  } else if (estado == "q2") {
    if (letra == 'a' || letra == 'b') {
      estado = "q2"
    } else if (letra == 'c') {
      estado = "q_accept";
    } else {
      estado = "q_dead";
    }
  } else if (estado == "q_final") {
    Serial.println("Palabra aceptada.");
    while (true);
  } else if (estado == "q_dead") {
    Serial.println("Palabra inválida. Estado de muerte alcanzado.");
    while (true);
  }
}

int getRojo() {
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  return pulseIn(out, LOW);
}

int getAzul() {
  digitalWrite(s2, LOW);
  digitalWrite(s3, HIGH);
  return pulseIn(out, LOW);
}

int getVerde() {
  digitalWrite(s2, HIGH);
  digitalWrite(s3, HIGH);
  return pulseIn(out, LOW);
}
