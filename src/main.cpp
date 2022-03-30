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

byte currCol = 0;
byte currRow = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  lcd.begin(COLUMNS, ROWS);
  lcd.setBacklight(WHITE);
  lcd.clear();
  lcd.home();
}

void waitForBytesAvailable(byte bytes) {
  while (Serial.available() < bytes) {
    ;
  }
}

void loop() {
  waitForBytesAvailable(1);
  char cmd = Serial.read();
  switch (cmd) {
    case 'r': {
      lcd.clear();
      currCol = 0;
      currRow = 0;
      lcd.setCursor(currCol, currRow);
      break;
    }
    case 'd': {
      lcd.clear();
      break;
    }
    case 'h': {
      currCol = 0;
      currRow = 0;
      lcd.setCursor(currCol, currRow);
      break;
    }
    case 'c': {
      waitForBytesAvailable(1);
      char subcmd = Serial.read();
      switch (subcmd) {
        case 'c': {
          long nextCol = Serial.parseInt();
          if (nextCol != -1) {
            currCol = nextCol;
          }
          break;
        }
        case 'r': {
          long nextRow = Serial.parseInt();
          if (nextRow != -1) {
            currRow = nextRow;
          }
          break;
        }
        default: {
          break;
        }
      }
      lcd.setCursor(currCol, currRow);
      break;
    }
    case 's': {
      waitForBytesAvailable(1);
      char subcmd = Serial.read();
      switch (subcmd) {
        case 'c': {
          Serial.println(COLUMNS);
          break;
        }
        case 'r': {
          Serial.println(ROWS);
          break;
        }
        default: {
          break;
        }
      }
      break;
    }
    case 'p': {
      while (true) {
        waitForBytesAvailable(1);
        char chr = Serial.read();
        if (chr == '\n' || chr == '\r') {
          break;
        }
        lcd.print(chr);
      }
    }
    default: {
      break;
    }
  }
}
