int RPWM = 5;
int LPWM = 6;

const int trigPin = 10;  // Nuevo pin TRIG
const int echoPin = 11;  // Nuevo pin ECHO

char letra = 'd'; // Último símbolo leído
String estado = "q0"; // Estado inicial

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);

  Serial.println("Estado: " + estado);
}

void loop() {
  avanzar();
  leerDistancia();
  if (letra != 'd') {
    transicion();
  }
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

void leerDistancia() {
  long duracion;
  float distancia;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duracion = pulseIn(echoPin, HIGH);
  distancia = duracion * 0.034 / 2 * 10; // mm

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" mm");

  // Si está fuera del rango válido, no detecta símbolo
    if (distancia > 95) {
    letra = 'd'; // no reconoce nada
    Serial.println("Muy lejos, no se detecta símbolo");
    avanzar();
    // return; salir de la función
  }

  letra = 'd'; // valor por defecto

  if (distancia < 40) {
    letra = 'c'; // negro (muy cerca)
  } else if (distancia >= 40 && distancia <= 60) {
    letra = 'a'; // azul (medio)
  } else if (distancia > 60 && distancia <= 90) {
    letra = 'b'; // rosa (lejano, pero dentro del rango)
  }

  if (letra != 'd') {
    Serial.println("Símbolo leído: " + String(letra));
  } else {
    Serial.println("Distancia dentro del rango, pero sin símbolo válido");
  }
}


void transicion() {
  Serial.println("Estado: " + estado);
  if (estado == "q0") {
    if (letra == 'c') {
      estado = "q1";
    } else if (letra == 'a' || letra == 'b') {
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
      estado = "q2";
    } else if (letra == 'c') {
      estado = "q_accept";
    } else {
      estado = "q_dead";
    }
  } else if (estado == "q_accept") {
    estado = "q_final";
  } else if (estado == "q_final") {
    Serial.println("Palabra aceptada.");
    analogWrite(RPWM, 0);
    analogWrite(LPWM, 0);
    while (true);
  } else if (estado == "q_dead") {
    Serial.println("Palabra inválida. Estado de muerte alcanzado.");
    analogWrite(RPWM, 0);
    analogWrite(LPWM, 0);
    while (true);
  }
}
