const int pinLDR = A0;  // Pin donde conectamos la fotocelda (LDR)
const int pinLED = 9;   // Pin donde conectamos el LED
int valorLDR = 0;       // Variable para almacenar el valor leído de la fotocelda

void setup() {
  pinMode(pinLED, OUTPUT);   // Configuramos el LED como salida
  Serial.begin(9600);        // Inicializamos la comunicación serial para monitorear
}

void loop() {
  valorLDR = analogRead(pinLDR);  // Leemos el valor de la fotocelda
  Serial.println(valorLDR);       // Imprimimos el valor en el Monitor Serie

  if (valorLDR < 500) {   // Si la luz es baja (umbral de 500, puedes ajustarlo)
    digitalWrite(pinLED, HIGH);  // Enciende el LED
  } else {
    digitalWrite(pinLED, LOW);   // Apaga el LED
  }

  delay(100);  // Pausa de 100 ms
}
