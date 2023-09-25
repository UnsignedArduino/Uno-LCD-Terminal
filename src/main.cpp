#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>

#define COLUMNS 16
#define ROWS 2
#define COLORFUL true

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

#define OFF 0x0
#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7 

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
      break;
    }
    case 'd': {
      lcd.clear();
      break;
    }
    case 'h': {
      currCol = 0;
      currRow = 0;
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
      break;
    }
    case 'a': {
      waitForBytesAvailable(1);
      char subcmd = Serial.read();
      switch (subcmd) {
        case 'w': {
          Serial.println(COLUMNS);
          break;
        }
        case 'h': {
          Serial.println(ROWS);
          break;
        }
        case 'c': {
          Serial.println(COLORFUL ? 1 : 0);
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
        lcd.write(chr);
      }
    }
    case 'b': {
      waitForBytesAvailable(1);
      char color = Serial.read();
      switch (color) {
        case 'o': {
          lcd.setBacklight(OFF);
          break;
        }
        case 'r': {
          lcd.setBacklight(RED);
          break;
        }
        case 'y': {
          lcd.setBacklight(YELLOW);
          break;
        }
        case 'g': {
          lcd.setBacklight(GREEN);
          break;
        }
        case 't': {
          lcd.setBacklight(TEAL);
          break;
        }
        case 'b': {
          lcd.setBacklight(BLUE);
          break;
        }
        case 'v': {
          lcd.setBacklight(VIOLET);
          break;
        }
        case 'w': {
          lcd.setBacklight(WHITE);
          break;
        }
      }
    }
    default: {
      break;
    }
  }
  lcd.setCursor(currCol, currRow);
}
