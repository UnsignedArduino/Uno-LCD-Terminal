#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

#define OFF 0x0
#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7 

const byte COLUMNS = 16;
const byte ROWS = 2;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  lcd.begin(COLUMNS, ROWS);
  lcd.setBacklight(WHITE);
}

void loop() {
  lcd.clear();
  lcd.home();
  lcd.print(millis());
  delay(100);
}
