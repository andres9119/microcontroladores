#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int Trigger = 2;   //Pin digital 2 para el Trigger del sensor
const int Echo = 3;      //Pin digital 3 para el Echo del sensor

// Dirección del LCD I2C (puede variar entre 0x27 o 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Configura la dirección según tu pantalla LCD

void setup() {
  Serial.begin(9600);  // Inicializamos la comunicación serial
  pinMode(Trigger, OUTPUT); //Pin Trigger como salida
  pinMode(Echo, INPUT);     //Pin Echo como entrada
  digitalWrite(Trigger, LOW); //Inicializamos el pin Trigger en LOW
  
  // Inicializamos la pantalla LCD
  lcd.init();
  lcd.backlight();  // Activa la luz de fondo de la pantalla
  lcd.setCursor(0, 0);  // Colocamos el cursor en la primera línea, columna 0
  lcd.print("Distancia:");
}

void loop() {
  long t; //tiempo que demora en llegar el eco
  long d; //distancia en centímetros

  // Enviar un pulso de 10 microsegundos
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  
  // Medir el ancho del pulso en el pin Echo
  t = pulseIn(Echo, HIGH);
  
  // Calcular la distancia en cm (según la fórmula del sensor ultrasónico)
  d = t / 58.2;  // Ajustamos para obtener la distancia en centímetros
  
  // Mostrar la distancia en la pantalla LCD
  lcd.setCursor(0, 1);  // Colocar el cursor en la segunda línea
  lcd.print("                ");  // Limpiar la línea anterior
  lcd.setCursor(0, 1);  // Volver a la segunda línea
  lcd.print(d);          // Imprimir la distancia medida
  lcd.print(" cm");      // Añadir las unidades
  
  // También mostramos la distancia en el monitor serie
  Serial.print("Distancia: ");
  Serial.print(d);
  Serial.println(" cm");

  // Pequeña pausa antes de la siguiente medición
  delay(1000);
}
