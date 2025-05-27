const int RPWM = 5;
const int LPWM = 6;
const int trigPin = 10;
const int echoPin = 11;

// Constantes de distancia en mm
const int DIST_CERCANA = 40;
const int DIST_MEDIA = 60;
const int DIST_LEJANA = 90;

// Configuración de movimiento
const int VELOCIDAD = 120;
const int DURACION_AVANCE = 1200;
const int DURACION_RETROCESO = 1000;

// Variables del sistema
char letra = 'd';
String estado = "q0";
unsigned long tiempoInicioMovimiento = 0;
bool enMovimiento = false;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);
  
  analogWrite(RPWM, 0);
  analogWrite(LPWM, 0);
}

void loop() {
  if (!enMovimiento) {
    leerDistancia();
    
    if (letra != 'd') {
      transicion();
    }
    delay(100);
  } else {
    if ((estado == "q1" || estado == "q2" || estado == "q5") && (millis() - tiempoInicioMovimiento >= DURACION_AVANCE)) {
      detener();
      enMovimiento = false;
    } 
    else if ((estado == "q3" || estado == "q4") && (millis() - tiempoInicioMovimiento >= DURACION_RETROCESO)) {
      detener();
      enMovimiento = false;
    }
  }
}

// Funciones de movimiento
void avanzar() {
  analogWrite(RPWM, VELOCIDAD);
  analogWrite(LPWM, 0);
  tiempoInicioMovimiento = millis();
  enMovimiento = true;
}

void retroceder() {
  analogWrite(LPWM, VELOCIDAD);
  analogWrite(RPWM, 0);
  tiempoInicioMovimiento = millis();
  enMovimiento = true;
}

void detener() {
  analogWrite(RPWM, 0);
  analogWrite(LPWM, 0);
}

// Función del sensor simplificada
void leerDistancia() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duracion = pulseIn(echoPin, HIGH, 30000);
  float distancia = duracion * 0.034 / 2 * 10;

  // Solo imprimir distancia
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" mm");

  letra = 'd';
  
  if (distancia > 95) {
    letra = 'd';
    return;
  }

  if (distancia > 2 && distancia < DIST_CERCANA) {
    letra = 'c';
  } else if (distancia >= DIST_CERCANA && distancia <= DIST_MEDIA) {
    letra = 'a';
  } else if (distancia > DIST_MEDIA && distancia <= DIST_LEJANA) {
    letra = 'b';
  }

  if (letra != 'd') {
    Serial.print("Símbolo: ");
    Serial.println(letra);
  }
}

// Máquina de estados simplificada
void transicion() {
  Serial.print("Estado: ");
  Serial.print(estado);
  Serial.print(" -> ");
  
  if (estado == "q0") {
    if (letra == 'c') {
      estado = "q1";
      avanzar();
    } else if (letra == 'a' || letra == 'b') {
      estado = "q_dead";
    }
  } else if (estado == "q1") {
    if (letra == 'a') {
      estado = "q2";
      avanzar();
    } else if(letra == 'b' || letra == 'c') {
      estado = "q_dead";
    }
  } else if (estado == "q2") {
    if (letra == 'a' || letra == 'b') {
      estado = "q2";
      avanzar();
    } else if (letra == 'c') {
      estado = "q3";
      retroceder();
    } 
  } else if (estado == "q3") {
    if (letra == 'b'){
      estado = "q4";
      retroceder();
    }
    else if (letra == 'a' || letra == 'c') {
      estado= "q_dead";
    }
  } else if(estado == "q4"){
    if( letra == 'a'){
      estado = "q5";
      avanzar();
    }
    else if (letra == 'b' || letra== 'c'){
      estado = "q_dead";
    }
  } else if(estado == "q5" ) {
    if(letra == 'b' ) {
      avanzar();
      estado = "q_final";
    }
    else if( letra == 'a' || letra == 'c') {
      estado = "q_dead";
    }
  }
  
  Serial.println(estado);
  
  if (estado == "q_final") {
    Serial.println("Aceptado");
    finalizarPrograma();
  } else if (estado == "q_dead") {
    Serial.println("Rechazado");
    finalizarPrograma();
  }
}

void finalizarPrograma() {
  detener();
  while(true);
}
