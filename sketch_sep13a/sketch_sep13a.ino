#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Dirección del LCD I2C (puede variar entre 0x27 o 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Configura la dirección según tu pantalla LCD

void setup() {
  // Inicializa la pantalla LCD
  lcd.init();
  lcd.backlight();  // Activa la luz de fondo de la pantalla

  // Mostrar mensaje de bienvenida
  lcd.setCursor(0, 0);  // Coloca el cursor en la primera línea, columna 0
  lcd.print("Bienvenido a");
  
  lcd.setCursor(0, 1);  // Coloca el cursor en la segunda línea, columna 0
  lcd.print("laboratorio!");
}

void loop() {
  // No se requiere nada en el loop para este ejemplo
}
