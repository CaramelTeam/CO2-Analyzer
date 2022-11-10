#include "MQ135.h"
#define SENSOR 32
#include <Adafruit_SSD1306.h>  //tiene que ser con mayusculas para q
#include <Wire.h> //implementa la comunicacion de i2c

#define AnchoPantalla 128  //iguales a las medidas de los led
#define AlturaPantalla 64


Adafruit_SSD1306 display(AnchoPantalla, AlturaPantalla, &Wire, -1);  //creacion de objeto para definir el tamaño del led y el apensor es un puntero hacia la clase
                                                                              //el -1 es un pin de reseteo

void setup() {
  Serial.begin(9600);
  delay(5000);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c); //inicialisamos la oled, el ultimo valor introducido hace referencia a la pantalla
  display.clearDisplay(); //Limpiador de cualquier residuo de la pantalla al momento de volver a cargar
}

void loop() {
  MQ135 gasSensor = MQ135(SENSOR);
  float air_quality = gasSensor.getPPM();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(2, 16);
  display.print("Calidad del aire: ");
  
  display.setTextSize(1);
  display.setCursor(100, 48);
  display.print("PPM");

  display.setTextSize(2);
  display.setCursor(10, 32);
  display.print(air_quality);
  display.display();
  display.clearDisplay();


  delay(2000);
}