const int LRD_PIN = A1; // Pin analógico utilizado para el sensor LRD
const int LED1_PIN = 2; // Pin digital utilizado para el LED
const int LED2_PIN = 3; // Pin digital utilizado para el LED
const int LED3_PIN = 4; // Pin digital utilizado para el LED
const int BOTON_PIN = 5; // Pin digital utilizado para el botón

bool leerSensor = false; // Variable para indicar si se debe leer el sensor

void setup() {
  Serial.begin(9600);
  pinMode(BOTON_PIN, INPUT_PULLUP); // Se establece el pin del botón como entrada con resistencia pull-up interna
  pinMode(LED1_PIN, OUTPUT); // Se establece el pin del LED como salida
  pinMode(LED2_PIN, OUTPUT); // Se establece el pin del LED como salida
  pinMode(LED3_PIN, OUTPUT); // Se establece el pin del LED como salida
}

void loop() {
  if (leerSensor) {
    int valor = analogRead(LRD_PIN);
    Serial.println(valor);
    if (valor < 100) { // Si el valor del LRD es menor a 100, se enciende el LED
      digitalWrite(LED1_PIN, HIGH);
      digitalWrite(LED2_PIN, HIGH);
      digitalWrite(LED3_PIN, HIGH);
      delay(100);
      digitalWrite(LED1_PIN, LOW);
      digitalWrite(LED2_PIN, LOW);
      digitalWrite(LED3_PIN, LOW);
      delay(100);
      digitalWrite(LED1_PIN, HIGH);
      digitalWrite(LED2_PIN, HIGH);
      digitalWrite(LED3_PIN, HIGH);
    } else {
      digitalWrite(LED1_PIN, LOW);
      digitalWrite(LED2_PIN, LOW);
      digitalWrite(LED3_PIN, LOW);
    }
  }
  
  // Se lee el estado del botón y se cambia el valor de la variable leerSensor cuando se presiona el botón
  if (digitalRead(BOTON_PIN) == LOW) {
    delay(50); // Se añade un pequeño retraso para evitar lecturas erróneas debido a rebotes del botón
    leerSensor = !leerSensor;
  }
}
